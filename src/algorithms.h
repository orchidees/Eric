// algorithms.h
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "constants.h"

#include <cmath>
#include <limits>
#include <float.h>
#include <stdexcept>
#include <cstring>
#include <cassert>

// ------------------------------------------------------------------//

template <typename T>
inline T minimum(const T* values,
		int N, int& minPos) {
	if (1 > N) return 0;

	T min = values[0];
	for (int i = 0; i < N; ++i) {
		if (min > values[i]) {
			min = values[i];
			minPos = i;
		}
	}

	return min;
}

template <typename T>
inline T maximum(const T* values,
		int N, int& maxPos) {
	if (1 > N) return 0;

	T max = values[0];
	for (int i = 0; i < N; ++i) {
		if (max < values[i]) {
			max = values[i];
			maxPos = i;
		}
	}

	return max;
}

template <typename T>
T sum(const T* values,
		int N) {
	if (1 > N) return 0;

	T sum = 0.;
	for (int i = 0; i < N; ++i) {
		sum += values[i];
	}

	return sum;
}

template <typename T>
T mean(const T* values,
		int N) {
	if (1 > N) return 0;

	return sum(values, N) / N;
}


template <typename T>
void scale(const T* buff, T* out, int len, T factor) {
	for (int i = 0; i < len; ++i) {
		out[i] = buff[i] * factor;
	}
}

template <typename T>
void swapElem(T& a, T& b) {
	  T t = (a);
	(a) = (b);
	(b) = t;
}

template <typename T>
T kth_smallest(T a[], int n, int k) {
	  int i, j, l, m;
	  T x;
	l = 0;
	m = n - 1;
	while (l < m) {
		x = a[k];
		i = l;
		j = m;
		do {
			while (a[i] < x) i++;
			while (x < a[j]) j--;
			if (i <= j) {
				swapElem(a[i], a[j]);
				i++;
				j--;
			}
		} while (i <= j);
		if (j < k) l = i;
		if (k < i) m = j;
	}
	return a[k];
}

template <typename T>
T median(T a[], int n) {
	return kth_smallest(a, n, (((n) & 1) ? ((n) / 2) : (((n) / 2) - 1)));
}


// ------------------------------------------------------------------//

template <typename T>
inline T centroid(
		const T* weights,
		const T* values,
		int N) {
	T sumWeigth = 0;
	T sumWeigthDistance = 0;
	T distance = 0;
	T weigth = 0;
	T weigthDistance = 0;

	for (int index = 0; index < N; ++index) {
		distance = values[index];
		weigth = weights[index];
		weigthDistance = weigth * distance;
		sumWeigth += weigth;
		sumWeigthDistance += weigthDistance;
	}

	// FIXME: is it right or we should compare with != 0?
	return (sumWeigth >= MINIMUM_REASONABLE_THRESHOLD ?
			sumWeigthDistance / sumWeigth : 0);
}

template <typename T> inline T stddev(const T* weights, const T* values, T mean, int N);

template <typename T>
inline T stddev(const T* weights, const T* values, T mean, int N) {
	if (N <= 0) return 0;

	T max = weights[0];
	for (int f = 0; f < N; ++f) {
		if (weights[f] >= max) max = weights[f];
	}
	T scaledMax = 0.3 * max;

	T sumWeight = 0.0;
	T sumDistance = 0.0;
	for (int index = 0; index < N; index++) {
		T tmp = values[index] - mean;
		T value = tmp * tmp;
		T weight = weights[index];
		if (weight <= scaledMax) weight = 0;
		T distance = value * weight;

		sumWeight += weight;
		sumDistance += distance;
	}

	T stddev = 0.0;
	if (0 != sumWeight) {
		stddev = sumDistance / sumWeight;
	} else {
		stddev = 0.;

	}
	return std::sqrt(stddev);
}

template <typename T>
inline T moment(
		const T* weights,
		const T* values,
		int N,
		int order,
		T centroid) {
	T sumWeigth = 0;
	T sumWeigthDistance = 0;
	T distance = 0;
	T weigth = 0;
	T weigthDistance = 0;

	for (int index = 0; index < N; ++index) {
		distance = values[index];
		distance -= centroid;
		distance = std::pow(distance, order);
		weigth = weights[index];
		weigthDistance = weigth * distance;
		sumWeigth += weigth;
		sumWeigthDistance += weigthDistance;
	}

	return (sumWeigth != 0 ? sumWeigthDistance / sumWeigth : 0);
}

template <typename T>
void normalize(const T* data, T* result, int N) {
	T min = data[0];
	T max = data[0];

	for (int i = 0; i < N; ++i) {
		if (max < data[i]) max = data[i];
		if (min > data[i]) min = data[i];
	}

	double delta = max - min;
	//T fmin = fabs(min);
	for (int i = 0; i < N; ++i) {
		result[i] = delta != 0 ? ((data[i] - min) / (max - min)): 0;
		//result[i] += min;
	}
}

template <typename T>
void normalize2(const T* data, T* result, int N) {
	T* weights = new T[N];
	for (int i = 0; i < N; ++i) weights[i] = 1;

	T mean = centroid (weights, data, N);
	T stdd = stddev (weights, data, mean, N);


	for (int i = 0; i < N; ++i) {
		result[i] = stdd != 0 ? ((data[i] - mean) / stdd) : 0;
		//result[i] += mean;
	}
	delete [] weights;
}

template <typename T>
void unnormalize(const T* data, T* result, int N) {
	T min = data[0];
	T max = data[0];

	for (int i = 0; i < N; ++i) {
		if (max < data[i]) max = data[i];
		if (min > data[i]) min = data[i];
	}

	double delta = max - min;
	//T fmin = fabs(min);
	for (int i = 0; i < N; ++i) {
		result[i] = (data[i] * delta) + min;
		//result[i] += min;
	}
}

template <typename T>
void unnormalize2(const T* data, T* result, int N) {
	T* weights = new T[N];
	for (int i = 0; i < N; ++i) weights[i] = 1;

	T mean = centroid (weights, data, N);
	T stdd = stddev (weights, data, mean, N);


	for (int i = 0; i < N; ++i) {
		result[i] = (data[i]* stdd) + mean;
		//result[i] += mean;
	}
	delete [] weights;
}

template <typename T>
static inline T linreg(
		const T* weights,
		const T* values,
		int N,
		T& step) {
	int index;
	int nbValue = N;

	T Xk = 0;
	T Yk = 0;
	T Xk2 = 0;
	T XkYk = 0;

	T sumXk = 0;
	T sumYk = 0;
	T sumXk2 = 0;
	T sumXkYk = 0;

	T slope = 0;

	for (index = 0; index < nbValue; index++) {
		Xk = values[index];
		Yk = weights[index];
		Xk2 = Xk * Xk;
		XkYk = Xk * Yk;

		sumXk += Xk;
		sumYk += Yk;
		sumXkYk += XkYk;
		sumXk2 += Xk2;
	}

	T numSlope = ((T) nbValue) * sumXkYk - (sumXk * sumYk);
	T numStep = sumXk2 * sumYk - sumXk * sumXkYk;
	T denSlope = ((T) nbValue) * sumXk2 - std::pow((T)sumXk, (T)2.0);

	if (0 != denSlope) {
		slope = numSlope / denSlope;
		step = numStep / denSlope;
	} else {
		slope = 0;
		step = 0;
	}
	return slope;
}

// -------------------------------------------------------------- //

template <typename T>
T inner_prod (const T* a, const T* b, int size) {
	// NB: it assumes vector have the same size
	T sum = 0;

	for (int i = 0; i < size; ++i) {
		T s = a[i] * b[i];
		sum += s;
	}
	if (std::isnan(sum) || std::isinf(sum)) return 0;
	else return sum;
}

template <typename T>
T edistance (const T* a, const T* b, int size) {
	// NB: it assumes vector have the same size
	T sum = 0;

	for (int i = 0; i < size; ++i) {
		T s = a[i] - b[i];
		sum += s * s;
	}
	if (std::isnan(sum) || std::isinf(sum)) return 0;
	else return std::sqrt(sum);
}

template <typename T>
T mahalanobis (const T* a, const T* b, int size) {
	// NB: it assumes vector have the same size
	T* w = new T[size];
	for (int i = 0; i < size; ++i) {
		w[i] = (T) 1. / size;
	}

	T m = mean(a, size);
	T stdd = stddev(w, a, m, size);

	T v = 0, d = 0;
	for (int i = 0; i < size; ++i) {
		v = (b[i] - a[i]) / stdd;
		d += (v * v);
	}
	if (std::isnan(d) || std::isinf(d)) return 0;
	else return std::exp(-d);
}

template <typename T>
T cosineSimilarity (const T* a, const T* b, int size) {
	// NB: it assumes vector have the same size
	int dotProd = 0;
	T lenA = 0;
	T lenB = 0;

	for (int i = 0; i < size; ++i) {
		dotProd += (a[i] * b[i]);
		lenA += (a[i] * a[i]);
		lenB += (b[i] * b[i]);
	}

	T den = std::sqrt(lenA * lenB);
	if (std::isnan(den) || std::isinf(den)) return 0;
	return den != 0 ? ((T) dotProd / den) : 0;
}

template <typename T>
T taxicab (const T* a, const T* b, int size) {
	// NB: it assumes vector have the same size
	T sum = 0;

	for (int i = 0; i < size; ++i) {
		T s = a[i] - b[i];
		sum += fabs(s);
	}
	if (std::isnan(sum) || std::isinf(sum)) return 0;
	else return sum;
}

template <typename T>
T kullbackLeibler (const T* a, const T* b, int size){
	T d = 0;
	for (int i = 0; i < size; ++i){
		if (b[i] != 0) {
			d += a[i] * log (a[i] / b[i]);
		}
		else {
			d += a[i] * log (a[i] / EPS);
		}
	}
	if (std::isnan(d) || std::isinf(d)) return 0;
	else return d;
}

// ------------------------------------------------------------------//

template <typename T>
void covmat(T** data, int n, int m, T** symmat) {
	T* mean = new T[m];

	for (int j = 0; j < m; j++) {
		mean[j] = 0.0;
		for (int i = 0; i < n; i++) {
			mean[j] += data[i][j];
		}
		mean[j] /= (T) n;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			data[i][j] -= mean[j];
		}
	}

	for (int j1 = 0; j1 < m; j1++) {
		for (int j2 = j1; j2 < m; j2++) {
			symmat[j1][j2] = 0.0;
			for (int i = 0; i < n; i++) {
				symmat[j1][j2] += data[i][j1] * data[i][j2];
			}
			symmat[j2][j1] = symmat[j1][j2];
		}
	}

	delete [] mean;
}

// ------------------------------------------------------------------//

template <typename T>
void kmeans(T** data, int n, int m, int k, T t, int* labels, T** centroids) {
	int h, i, j;
	T old_error, error = DBL_MAX;
	T **c = centroids;
	T **c1 = (T**) new T*[k];
	int* counts = (int*) new int[k];

	assert(data && k > 0 && k <= n && m > 0 && t >= 0);

	for (h = i = 0; i < k; h += n / k, i++) {
		c1[i] = (T*) calloc(m, sizeof (T));
		if (!centroids) {
			c[i] = (T*) new T[m];
		}
		for (j = m; j-- > 0; c[i][j] = data[h][j]);
	}

	do {
		old_error = error, error = 0;

		for (i = 0; i < k; counts[i++] = 0) {
			for (j = 0; j < m; c1[i][j++] = 0);
		}

		for (h = 0; h < n; h++) {
			T min_distance = DBL_MAX;
			for (i = 0; i < k; i++) {
				T distance = 0;
				for (j = m; j-- > 0; distance += pow(data[h][j] - c[i][j], 2));
				if (distance < min_distance) {
					labels[h] = i;
					min_distance = distance;
				}
			}

			for (j = m; j-- > 0; c1[labels[h]][j] += data[h][j]);
			counts[labels[h]]++;
			error += min_distance;
		}

		for (i = 0; i < k; i++) {
			for (j = 0; j < m; j++) {
				c[i][j] = counts[i] ? c1[i][j] / counts[i] : c1[i][j];
			}
		}

	} while (fabs(error - old_error) > t);


	for (i = 0; i < k; i++) {
		delete [] c1[i];
	}

	delete [] c1;
	delete [] counts;
}

// -----------------------------------------------------------------------------

template <typename T>
T frand(T min, T max) {
	return ((max - min) * ((T)rand() / RMAX) + min);
}

#endif	// ALGORITHMS_H

// EOF
