#include "utils.hpp"
#include <NTL/RR.h>
#include <random>

NTL::ZZ_pX random_poly(long degree, const NTL::ZZ& bound) {
    NTL::ZZ_pX result;
    for (long i = 0; i <= degree; ++i) {
        // Generate random coefficients
        SetCoeff(result, i, NTL::random_ZZ_p());
    }
    return result;
}

NTL::ZZ_pX random_binary_poly(long degree) {
    NTL::ZZ_pX result;
    for (long i = 0; i <= degree; ++i) {
        // Generate random binary coefficients (0 or 1)
        SetCoeff(result, i, NTL::random_ZZ_p() % 2);
    }
    return result;
}

NTL::ZZ_pX random_normal_poly(long degree, double stddev) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, stddev);

    NTL::ZZ_pX result;
    for (long i = 0; i <= degree; ++i) {
        // Generate coefficients from a normal distribution
        double sample = d(gen);
        SetCoeff(result, i, NTL::conv<NTL::ZZ_p>(NTL::RoundToZZ(NTL::conv<NTL::RR>(sample))));
    }
    return result;
}
