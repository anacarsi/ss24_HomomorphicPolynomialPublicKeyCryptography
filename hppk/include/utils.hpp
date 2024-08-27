
#pragma once

#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include <vector>

NTL::ZZ_pX random_poly(long degree, const NTL::ZZ& bound);
NTL::ZZ_pX random_binary_poly(long degree);
NTL::ZZ_pX random_normal_poly(long degree, double stddev);
