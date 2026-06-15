
#pragma once
#ifdef _WIN32
#define CIPHER_API __declspec(dllexport)
#else
#define CIPHER_API __attribute__((visibility("default")))
#endif

typedef void* cipher_t;

#ifdef __cplusplus
extern "C" {
#endif

    CIPHER_API cipher_t* cipher_create_caesar(int key);
    CIPHER_API cipher_t* cipher_create_vigenere(const char* key);
    CIPHER_API char* cipher_encrypt(cipher_t* cipher, const char* text);
    CIPHER_API char* cipher_decrypt(cipher_t* cipher, const char* text);
    CIPHER_API void      cipher_destroy(cipher_t* cipher);
    CIPHER_API void      cipher_free(char* str);

#ifdef __cplusplus
}
#endif