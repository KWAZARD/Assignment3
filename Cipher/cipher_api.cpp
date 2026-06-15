#include "cipher_api.h"
#include "CaesarCipher.h"
#include "Cipher.h"
#include "VigenereCipher.h"
#include <cstring>
#include <iostream>



extern "C" {
	/* Factory — creates the cipher object and returns an opaque handle */
	cipher_t* cipher_create_caesar(int key)
	{
		return (cipher_t*)new CaesarCipher(key);
	}
	cipher_t* cipher_create_vigenere(const char* key) {
		return (cipher_t*)new VigenereCipher(key);
	}
	/* Operations — behave differently depending on which cipher was
	created */
	char* cipher_encrypt(cipher_t* cipher, const char* text)
	{
		Cipher* obj = (Cipher*)cipher;
		std::string result = obj->encrypt(text);
		char* encryptedResult = new char[result.length() + 1];
		memcpy(encryptedResult, result.c_str(), result.length() + 1);
		return encryptedResult;
	}
	char* cipher_decrypt(cipher_t* cipher, const char* text) {
		Cipher* obj = (Cipher*)cipher;
		std::string result = obj->decrypt(text);
		char* decryptedResult = new char[result.length() + 1];
		memcpy(decryptedResult, result.c_str(), result.length() + 1);
		return decryptedResult;
	}
	/* Cleanup */
	void cipher_destroy(cipher_t* cipher)
	{
		delete (Cipher*)cipher;
	}
	void cipher_free(char* str)
	{
		if (str != nullptr) {
			delete[] str;
		}
	}
}