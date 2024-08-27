#pragma once

#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include <tuple>

struct PublicKey {
    NTL::ZZ_pX a, b;
};

struct SecretKey {
    NTL::ZZ_pX s;
};

struct Ciphertext {
    NTL::ZZ_pX c0, c1;
};

std::tuple<PublicKey, SecretKey> keygen(long degree, const NTL::ZZ& q, const NTL::ZZ_pX& poly_mod);
Ciphertext encrypt(const PublicKey& pk, long m, const NTL::ZZ& t, const NTL::ZZ_pX& poly_mod);
long decrypt(const SecretKey& sk, const Ciphertext& ct, const NTL::ZZ& t, const NTL::ZZ_pX& poly_mod);
Ciphertext add_ciphertexts(const Ciphertext& ct1, const Ciphertext& ct2, const NTL::ZZ_pX& poly_mod);
