// ClassicVerb.h
//

#ifndef CLASSICVERB_H
#define CLASSICVERB_H


#include <cmath>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

#define undenormalise(sample) if(((*(unsigned int*)&sample)&0x7f800000)==0) sample=0.0f

template <typename T>
class FIR {
public:
    FIR (const T* coefs, int ncoeff, float gain = 1.) {
        m_length = ncoeff;
        m_impulseResponse = new T[m_length];
        m_AudioDelayLine = new T[m_length];
        impulse (coefs, ncoeff);
        m_gain = gain;
    }
    virtual ~FIR () {
        delete [] m_impulseResponse;
        delete [] m_AudioDelayLine;
    }
    virtual T* process (const T* input, T* output, int size) {
        for (int j = 0; j < size; ++j) {
            output[j] = 0.;
            m_AudioDelayLine[0] = input[j] * m_gain;
            for (unsigned int i = m_length - 1; i > 0; i--) {
                output[j] += m_impulseResponse[i] * m_AudioDelayLine[i];
                m_AudioDelayLine[i] = m_AudioDelayLine[i - 1];
            }
            output[j] += m_impulseResponse[0] * m_AudioDelayLine[0];
        }
        return output;
    }
    void impulse (const T* coefs, int ncoeff) {
        for (int i = 0; i < ncoeff; ++i) {
            m_impulseResponse[i] = coefs[i];
            m_AudioDelayLine[i] = 0.;
        }
    }
private:
    T m_gain;
    int m_length;
    T* m_AudioDelayLine;
    T* m_impulseResponse;
};

template <typename T>
class AudioDelay {
public:
    AudioDelay (float sr, float dur, float feedback) :
        m_ptr (0), m_feedback (feedback) {
        m_samples = (long) (sr * dur);
        if (m_samples <= 0) m_samples = 1;

        allocate ();
    }
    AudioDelay (float sr, int samples, float feedback) :
        m_ptr (0), m_feedback (feedback) {
        m_samples = samples;
        allocate ();
    }
    virtual ~AudioDelay () {
        delete [] m_delay;
    }
    long length () const {
        return m_samples;
    }
    void reset () {
        for (long i = 0; i < m_samples + 10; ++i) {
            m_delay[i] = (T) 0.;
        }
    }
    void feedback (float f) {
        m_feedback = f;
    }
    virtual T* process (const T* input, T* output, long size) {
        for (long i = 0; i < size; ++i) {
            output[i] = m_delay[m_ptr];
            //undenormalise (output[i]);
            m_delay[m_ptr] = input[i] +  (m_feedback * output[i]);
            m_ptr++;
            m_ptr %= m_samples;
        }

        return output;
    }
protected:
    T* m_delay;
    long m_ptr;
    float m_feedback;
    long m_samples;
private:
    void allocate () {
        m_delay = new T[m_samples + 10];
        reset ();
    }
};

template <typename T>
class Comb : public AudioDelay <T> {
public:
    typedef AudioDelay <T> Base;
    Comb (float sr, float dur, float feedback) :
        AudioDelay <T> (sr, dur, feedback),
        m_damp (0), m_udamp (1), m_lp (0) {}
    Comb (float sr, int samples, float feedback) :
        AudioDelay <T> (sr, samples, feedback),
        m_damp (0), m_udamp (1), m_lp (0) {}
    void damp (float d, bool reset = false) {
        m_damp = d;
        m_udamp = 1. - m_damp;
        if (reset) {
            m_lp = 0;
        }
    }
    virtual T* process (const T* input, T* output, long size) {
        for (long i = 0; i < size; ++i) {
            output[i] = Base::m_delay[Base::m_ptr];
            //undenormalise (output[i]);
            m_lp = (output[i] * m_udamp) + (m_lp * m_damp);
            //undenormalise (m_lp);
            Base::m_delay[Base::m_ptr] = input[i] + (Base::m_feedback * m_lp);
            Base::m_ptr++;
            Base::m_ptr %= Base::m_samples;
        }

        return output;
    }
private:
    float m_damp;
    float m_udamp;
    float m_lp;
};

template <typename T>
class Allpass : public AudioDelay <T> {
public:
    typedef AudioDelay <T> Base;
    Allpass (float sr, float dur, float feedback) :
        AudioDelay <T> (sr, dur, feedback) {}
    Allpass (float sr, int samples, float feedback) :
        AudioDelay <T> (sr, samples, feedback) {}
    virtual T* process (const T* input, T* output, long size) {
        for (long i = 0; i < size; ++i) {
            float buff = Base::m_delay[Base::m_ptr];
            //undenormalise (buff);
            output[i] = -(input[i]) + buff;
            Base::m_delay[Base::m_ptr] = input[i] + (Base::m_feedback * buff);
            Base::m_ptr++;
            Base::m_ptr %= Base::m_samples;

        }
        return output;
    }
};

static const int COMBS_LEN[] = {
    1116,
    1188,
    1277,
    1356,
    1422,
    1491,
    1557,
    1617,
    1663,
    1699,
    1741,
    1801,
    1867,
    1889,
    1931,
    1973,
    1993,
    2017,
    2113,
    2293,
    2467,
    2647
};
static const int MAXCOMBS = sizeof (COMBS_LEN) / sizeof (int);

static const int ALLPASS_LEN[] = {
    556,
    441,
    341,
    225,
    181,
    163,
    151,
    137,
    113,
    91,
    68,
    53,
    37
};
static const int MAXALLPASS = sizeof (ALLPASS_LEN) / sizeof (int);

template <typename T>
class ClassicVerb {
private:
    ClassicVerb& operator= (ClassicVerb&);
    ClassicVerb (const ClassicVerb&);
public:
    ClassicVerb (float sr, int maxsize, int density, int diffusion, int offset, float ratio = 1.) :
        m_t60 (2.3), m_minDamp (.1), m_maxDamp (.9), m_direct (.7), m_early (.35), m_tail (.3) {
        m_sr = sr;
        if (m_sr <= 0) throw std::runtime_error ("invalid sr specified");
        if (density <= 0 || density > MAXCOMBS) {
            std::stringstream err;
            err << "too many density units; max allowed is " << MAXCOMBS;
            throw std::runtime_error (err.str ());
        }
        if (diffusion <= 0 || diffusion > MAXALLPASS) {
            std::stringstream err;
            err << "too many diffusion units; max allowed is " << MAXCOMBS;
            throw std::runtime_error (err.str ());
        }
        m_ratio = ratio;
        if (m_ratio <= 0) throw std::runtime_error ("invalid ratio specified");
        m_offset = offset;
        if (offset < 0) throw std::runtime_error ("invalid offset specified");
        //m_size = bsize;
        if (maxsize <= 0) throw std::runtime_error ("invalid size specified");

        alloc (density, diffusion, maxsize);
        m_earlyRef = 0;
        earlyRef (0.05, 18, .9999);
        m_preAudioDelay = 0;
        preAudioDelay (0.0001);

        m_rescale = 0.001 + (1. / (diffusion * diffusion + density)) / diffusion;
    }
    virtual ~ClassicVerb () {
        for (unsigned int i = 0; i < m_combs.size (); ++i) {
            delete m_combs[i];
            delete [] m_cbuff[i];
        }

        for (unsigned int i = 0; i < m_allpass.size (); ++i) {
            delete m_allpass[i];
            delete [] m_abuff[i];
        }
        delete m_earlyRef;
        delete m_preAudioDelay;

        delete [] m_AudioDelay;
        delete [] m_tmp0;
        delete [] m_tmp1;
        delete [] m_tmp2;
    }
    void earlyRef (float dur, int density, float diffusion) {
        if (m_earlyRef) {
            delete m_earlyRef;
        }
        if (dur < 0) throw std::runtime_error ("invalid total duration for early reflections");

        int samples = (int) (dur * m_sr);
        if (samples < density) samples = density;
        if (samples <= 0) samples = 1;

        T* c = new T[samples];
        T* d = new T[samples];
        for (int i = 0; i < samples; ++i) c[i] = 0.;
        c[samples - 1] = 1. / exp (1.);

        int sign = 1;
        for (int i = 0; i < density; ++i) {
            int r = (int) frand (0, samples);
            c[r] = (float) sign / exp ((T) r / samples);
            sign -= sign;
        }

        Allpass <T> alp (m_sr, dur, diffusion);
        alp.process (c, d, samples);
        //for (int i = 0; i < samples; ++i) std::cout << c[i] << std::endl;
        for (int i = 0; i < samples; ++i) {
            c[i] += d[i];
        }
        m_earlyRef = new FIR<T> (c, samples);
        delete [] c;
        delete [] d;
    }
    void earlyRef (float dur, const T* coefs) {
        if (m_earlyRef) {
            delete m_earlyRef;
        }
        if (dur < 0) throw std::runtime_error ("invalid total duration for early reflections");

        int samples = dur * m_sr;
        if (samples <= 0) samples = 1;

        float* c = new float[samples];

        for (int i = 0; i < samples; ++i) {
            c[i] = coefs[i];
        }

        m_earlyRef = new FIR<T> (c, samples);
        delete [] c;
    }
    void preAudioDelay (float dur) {
        if (m_preAudioDelay) {
            delete m_preAudioDelay;
        }
        if (dur < 0) throw std::runtime_error ("invalid preAudioDelay specified");
        m_preAudioDelay = new AudioDelay <T> (m_sr, dur, 0);
    }
    void t60 (float t) {
        m_t60 = t;
        if (m_t60 < 0) throw std::runtime_error ("invalid t60 specified");

        for (unsigned int i = 0; i < m_combs.size (); ++i) {
            float s = (float) ((COMBS_LEN[i] + m_offset)) * m_ratio;
            float fb = pow (10.0, (-3.0 * s / (m_t60 * m_sr)));
            m_combs[i]->feedback (fb);
        }
    }
    void damp (float min, float max) {

        if (min > max) min = max = 0.05;

        for (unsigned int i = 0; i < m_combs.size (); ++i) {
            m_combs[i]->damp (frand (min, max));
        }
    }
    void gains (float direct, float early, float tail) {
        m_direct = direct;
        if (m_direct < 0) throw std::runtime_error ("invalid gain for direct path");
        m_early = early;
        if (m_early < 0) throw std::runtime_error ("invalid gain for early reflections");
        m_tail = tail;
        if (m_tail < 0) throw std::runtime_error ("invalid gain for tail reverberation");
    }
    //
    virtual T* process (const T* input, T* output, int size) {
        for (int j = 0; j < size; ++j) {
            m_AudioDelay[j] = input[j] * m_rescale;
            output[j] = input[j] * m_direct;
        }

        m_preAudioDelay->process (m_AudioDelay, m_tmp0, size);
        //m_earlyRef->process (m_tmp0, m_tmp1, m_size);

        for (unsigned int i = 0; i < m_combs.size (); ++i) {
            m_combs[i]->process (m_tmp0, m_cbuff[i], size);
        }

        memset (m_tmp2, 0, sizeof (T) * size);
        for (unsigned int i = 0; i < m_combs.size (); ++i) {
            for (int j = 0; j < size; ++j) {
                m_tmp2[j] += m_cbuff[i][j];
            }
        }

        m_allpass[0]->process (m_tmp2, m_abuff[0], size);
        for (unsigned int i = 1; i < m_allpass.size (); ++i) {
            m_allpass[i]->process (m_abuff[i - 1], m_abuff[i], size);
        }

        for (int j = 0; j < size; ++j) {
            output[j] += (m_abuff[m_allpass.size () - 1][j] * m_tail); // + (m_tmp1[j] * m_early));
            //output[j] += m_tmp1[j];
        }

        return output;
    }
private:
    void alloc (int density, int diffusion, int bsize) {
        for (int i = 0; i < density; ++i) {
            float s = (float) ((COMBS_LEN[i] + m_offset)) * m_ratio * m_sr / 44100.;
            float fb = pow (10.0, (-3.0 * s / (m_t60 * m_sr)));
            Comb<T>* c = new Comb<T> (m_sr, (int) s, fb);
            c->damp (frand (m_minDamp, m_maxDamp));
            m_combs.push_back (c);

            T* t = new T[bsize];
            m_cbuff.push_back (t);
        }
        for (int i = 0; i < diffusion; ++i) {
            m_allpass.push_back (new Allpass<T> (m_sr, ALLPASS_LEN[i], .7));
            T* t = new T[bsize];
            m_abuff.push_back (t);
        }

        m_AudioDelay = new T[bsize];
        m_tmp0 = new T[bsize];
        m_tmp1 = new T[bsize];
        m_tmp2 = new T[bsize];
    }

    float frand (float min, float max) {
        float f = 0;
        short r = abs (rand ());
        f = fabs ((float) r / 32768);
        f *= (max - min);
        f += min;
        return f;
    }

    float m_sr;
    float m_t60;
    float m_minDamp;
    float m_maxDamp;
    float m_direct;
    float m_early;
    float m_tail;
    float m_rescale;
    float m_ratio;
    int m_offset;
    //int m_size;
    std::vector <Comb <T>* > m_combs;
    std::vector <Allpass <T>* > m_allpass;
    std::vector <T*> m_cbuff;
    std::vector <T*> m_abuff;
    T* m_AudioDelay;
    T* m_tmp0;
    T* m_tmp1;
    T* m_tmp2;

    AudioDelay<T>* m_preAudioDelay;
    FIR<T>* m_earlyRef;
};

#endif	// CLASSICVERB_H

// EOF
