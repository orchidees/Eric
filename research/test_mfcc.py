import librosa
import numpy as np
import matplotlib.pyplot as plt

(t, fs) = librosa.load("../../targets/vocal_chord.wav")
mfcc = librosa.feature.mfcc (y=t, sr=fs)
mfcc_mean = np.mean(mfcc, axis=1)
plt.plot(mfcc_mean)
plt.show ()

