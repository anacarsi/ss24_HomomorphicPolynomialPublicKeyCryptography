#include "hppk.hpp"
#include <iostream>

int main() {// Set up parameters for the encryption scheme
    long degree = 1024;  // Polynomial degree
    NTL::ZZ q = NTL::power2_ZZ(54);  // Modulus for the ring
    NTL::ZZ t = NTL::to_ZZ(256);  // Plaintext modulus
    NTL::ZZ_p::init(q);  // Initialize ZZ_p with modulus q

    // Create the polynomial modulus x^degree + 1
    NTL::ZZ_pX poly_mod;
    SetCoeff(poly_mod, 0, 1);  // Constant term
    SetCoeff(poly_mod, degree, 1);  // Highest degree term

    // Generate public and secret keys
    auto [pk, sk] = keygen(degree, q, poly_mod);

    // Example plaintexts
    long m1 = 5;
    long m2 = 7;

    // Encrypt the plaintexts
    Ciphertext ct1 = encrypt(pk, m1, t, poly_mod);
    Ciphertext ct2 = encrypt(pk, m2, t, poly_mod);

    // Perform homomorphic addition
    Ciphertext ct_sum = add_ciphertexts(ct1, ct2, poly_mod);

    // Decrypt the result
    long decrypted_sum = decrypt(sk, ct_sum, t, poly_mod);

    // Output results
    std::cout << "Decrypted sum: " << decrypted_sum << std::endl;
    std::cout << "Expected sum: " << (m1 + m2) % NTL::conv<long>(t) << std::endl;

    return 0;
}