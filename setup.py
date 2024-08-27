from setuptools import setup, Extension

# Extension module
extension_mod = Extension("mod_hppk.encryption", sources=["hppk/encryption.c", "wrapper/encryption.py"])

setup(
    name="ss24_HPPK",
    version="1.0",
    description="Homomorphic Polynomial Public Key Cryptography",
    author="Ana Carsi",
    ext_modules=[extension_mod]
)