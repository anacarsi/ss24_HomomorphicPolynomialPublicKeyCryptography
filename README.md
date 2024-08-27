# ss24_HomomorphicPolynomialPublicKeyCryptography
![Homomorphic Encryption](images/introduction.jpg)

Repository for the implementation of Homomorphic Polynomial Public Key Cryptography for posterior training and statistical analysis.
A review on the innovative asymmetric cryptographic method designed by Randy Kuang et al. (2024) for the post-quantum era is presented, in other to understand its relation with algebra and the properties of finite
fields. The hope is to bring understanding on cryptographic methods’ design. Its efficiency and security constraints are analysed as well.

# Introduction
Since the publication of the Diffie-Hellman key exchange and the RSA cryptosystem, public key cryptography has been a major field on cybersecurity research. However, a new threat appeared with the raise of quantum
computing, leading to the development of post-quantum cryptography (PQC). We can introduce Polynomial Public Key comparing it with other public-key methods: 

## Comparison of Cryptographic Methods
1. Advanced Encryption Standard (AES):
   - Uses the finite field GF(2^8)
   - Operations are internal in the field and highly efficient
   - Low memory requirements

2. Rivest-Shamir-Adleman (RSA):
   - Uses modular exponentiation in the ring Z/nZ
   - More complex than AES
   - Higher memory requirements (bigger key size) than AES

3. Polynomial Public Key Cryptography (PPKC):
   - Uses polynomials over a finite field to represent public key, private key, and encrypted message
   - Polynomials lie on finite fields Fp, where p is prime
   - Focuses on both secure key exchange and encryption/decryption
   - Can be slower than RSA, depending on polynomial sizes

# Methodology
Homomorphic Polynomial Public Key (HPPK) is an extension of PPKC and a specific form of homomorphic encryption. Here, the multivariate polynomials lie as well on finite fields, and the encryption method has
been proven to be partially homomorphic under addition and multiplication.
Comparing it to RSA, both use separate public and private keys, where the public key is used for encryption and the private key for decryption. However in HHPK the public key is derived from polynomial
multiplications over a finite field.

HPPK was originally designed for Key Encapsulation Mechanism, aiming to securely generate and share a secret symmetric key between two parties using public key cryptography. KEM consists of three steps: key
pair generation, encapsulation (encryption) to create a shared secret key, and decapsulation (decryption) for key recovery. 

# Analysis
A private key recovery attack with complexity O(2p(S1 + S2)) and a forgery attack with complexity O(S1 ∗ S2) was analysed. However, the evaluation of HPPK for digital signature shows it is an efficient method in key generation, signing, and verification processes. 

Plus, the adaptation of the Barrett-reduction algorithm helps reducing the overhead created through decapsulation and polynomial modular multiplication.
![Homomorphic Encryption](images/barrett.jpg)
