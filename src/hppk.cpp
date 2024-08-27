#include "hppk.hpp"
#include "utils.hpp"

std::tuple<PublicKey, SecretKey> keygen(long degree, const NTL::ZZ& q, const NTL::ZZ_pX& poly_mod) {
    NTL::ZZ_p::init(q);  // Initialize ZZ_p with modulus q

    // Generate secret key: a random binary polynomial
    NTL::ZZ_pX s = random_binary_poly(degree);

    // Generate a random polynomial for public key
    NTL::ZZ_pX a = random_poly(degree, q);

    // Generate error polynomial
    NTL::ZZ_pX e = random_normal_poly(degree, 3.2);

    // Compute b = -(a*s + e) mod poly_mod
    NTL::ZZ_pX b = (a * s + e) % poly_mod;
    b = -b;

    return std::make_tuple(PublicKey{a, b}, SecretKey{s});
}

Ciphertext encrypt(const PublicKey& pk, long m, const NTL::ZZ& t, const NTL::ZZ_pX& poly_mod) {
    long degree = deg(poly_mod);
    NTL::ZZ q = NTL::ZZ_p::modulus();

    // Generate random polynomials
    NTL::ZZ_pX u = random_binary_poly(degree);
    NTL::ZZ_pX e1 = random_normal_poly(degree, 3.2);
    NTL::ZZ_pX e2 = random_normal_poly(degree, 3.2);

    // Encode the message
    NTL::ZZ_p m_encoded = NTL::conv<NTL::ZZ_p>(m);
    NTL::ZZ_pX m_poly;
    SetCoeff(m_poly, 0, m_encoded);

    // Scale the message
    NTL::ZZ delta = q / t;
    NTL::ZZ_pX scaled_m = delta * m_poly;

    // Compute ciphertext components
    NTL::ZZ_pX c0 = (pk.b * u + e1 + scaled_m) % poly_mod;
    NTL::ZZ_pX c1 = (pk.a * u + e2) % poly_mod;

    return Ciphertext{c0, c1};
}

long decrypt(const SecretKey& sk, const Ciphertext& ct, const NTL::ZZ& t, const NTL::ZZ_pX& poly_mod) {
    NTL::ZZ q = NTL::ZZ_p::modulus();

    // Compute m = c0 + c1 * s mod poly_mod
    NTL::ZZ_pX m = (ct.c0 + ct.c1 * sk.s) % poly_mod;

    // Extract the constant term
    NTL::ZZ_p m_scalar = coeff(m, 0);
    NTL::ZZ m_zz = NTL::rep(m_scalar);

    // Scale and round to get the original message
    m_zz = (m_zz * t + q/2) / q;
    return NTL::conv<long>(m_zz % t);
}

Ciphertext add_ciphertexts(const Ciphertext& ct1, const Ciphertext& ct2, const NTL::ZZ_pX& poly_mod) {
    // Homomorphic addition is simply component-wise addition
    NTL::ZZ_pX c0 = (ct1.c0 + ct2.c0) % poly_mod;
    NTL::ZZ_pX c1 = (ct1.c1 + ct2.c1) % poly_mod;
    return Ciphertext{c0, c1};
}
