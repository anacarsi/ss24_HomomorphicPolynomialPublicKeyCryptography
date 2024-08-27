"""
IT-Security Project 2024 - Galois Theory and Homomorphic Polynomial Public Key Cryptography
Creator: Ana Carsi

This project is a Python implementation of the Homomorphic Polynomial Public Key Cryptography (HPPK) system 
described by Randy Kuang, Mahmoud Sayed, Maria Perepechaenko and Dafu Lou for Digital Signatures.
"""

import ctypes

class HPPKEncryptor:
    def __init__(self, public_key):
        self.library = ctypes.CDLL("./libencrypt.so")
        self.library.encrypt.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
        self.library.encrypt.restype = ctypes.c_char_p
        self.public_key = public_key

    """
    Define a wrapper for encryption.
    
    Args:
        plaintext: str
            The plaintext message to encrypt.

    Returns:
        str
            The encrypted ciphertext message.

    """
    def encrypt(self, plaintext) -> str:
        # Convert python string to C string
        c_data = ctypes.c_char_p(plaintext.encode('utf-8'))
        c_key = ctypes.c_char_p(self.public_key.encode('utf-8'))
        
        cipher_data = self.library.encrypt(c_data, c_key)
        # Convert C string to python string
        # return ctypes.cast(cipher_data, ctypes.c_char_p).value.decode('utf-8')
        return cipher_data.decode('utf-8')

