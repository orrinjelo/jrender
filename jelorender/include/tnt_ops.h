#pragma once

#include <cmath>
#include "tnt/tnt.h"
#include "tnt_types.h"


// L2 Norm
template<class T>
double l2Norm(T v) {
    double sum = 0.0;
    for (int i=0; i<v.dim1(); ++i)
        sum += v[i]*v[i];
    return std::sqrt(sum);
}

// Template normalize for normalizing a Array1D type
template<class T>
T normalizeVector(T v) {
    double l2 = l2Norm(v);
    assert(l2 != 0);
    for (int i=0; i<v.dim1(); ++i)
        v[i] = v[i] / l2;

    return v.copy();
}

// Dot product
template<class T>
double dotProduct(T v, T w) {
    double sum = 0.0;
    auto prod = v*w;
    for (int i=0; i<v.dim1(); ++i) {
        sum += prod[i];
    }
    return sum;
}

// Reflect vector v off of surface with normal n
template<class T>
T reflectVector(T v, T n) {
    double scalar = 2*dotProduct(v.copy(), n.copy());
    double_1darray nscale(3, 0.0);
    nscale[0] = n[0] * scalar;
    nscale[1] = n[1] * scalar;
    nscale[2] = n[2] * scalar;
    return v - nscale;
}
