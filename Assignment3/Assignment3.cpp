// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include "cipher_api.h"
#include <iostream>


typedef cipher_t* (*cipher_create_caesar_fn)(int key);
typedef cipher_t* (*cipher_create_vigenere_fn)(const char* key);
typedef char* (*cipher_encrypt_fn)(cipher_t* cipher, const char* text);
typedef char* (*cipher_decrypt_fn)(cipher_t* cipher, const char* text);
typedef void (*cipher_destroy_fn)(cipher_t* cipher);
typedef void (*cipher_free_fn)(char* str);
int main()
{

    HMODULE cipher = LoadLibrary(L"Cipher.dll");
    if (!cipher)
    {
        printf("DLL is not found\n");
        return 1;
    }
    cipher_create_caesar_fn cipher_create_caesar = (cipher_create_caesar_fn)GetProcAddress(cipher, "cipher_create_caesar");
    cipher_create_vigenere_fn cipher_create_vigenere = (cipher_create_vigenere_fn)GetProcAddress(cipher, "cipher_create_vigenere");

    cipher_decrypt_fn cipher_decrypt = (cipher_decrypt_fn)GetProcAddress(cipher, "cipher_decrypt");
    cipher_encrypt_fn cipher_encrypt = (cipher_encrypt_fn)GetProcAddress(cipher, "cipher_encrypt");

    cipher_destroy_fn cipher_destroy = (cipher_destroy_fn)GetProcAddress(cipher, "cipher_destroy");
    cipher_free_fn cipher_free = (cipher_free_fn)GetProcAddress(cipher, "cipher_free");


    while (1)
    {
        int choise;
        printf("Enter cipher:\n"
            "1- Caesar\n"
            "2- Vigenere\n"
            "3- Exit\n");
        scanf_s("%d", &choise);
        switch (choise)
        {
        case 1:
        {
            int input_key;
            printf("Enter key in number:\n");
            scanf_s("%d", &input_key);
            cipher_t* newCaesar = cipher_create_caesar(input_key);
            printf("Enter:\n"
                "1-Encrypt:\n"
                "2-Decrypt:\n");
            int a;
            scanf_s("%d", &a);
            switch (a)
            {
                case 1:
                {
                    std::string text;
                    printf("Enter text:\n");
                    std::cin >> text;
                    printf("Result: ");
                    char* end = cipher_encrypt(newCaesar, text.c_str());
                    printf(end);
                    printf("\n");
                    cipher_free(end);
                    cipher_destroy(newCaesar);
                    break;
                }
                case 2:
                {
                    std::string text;
                    printf("Enter text:\n");
                    std::cin >> text;
                    printf("Result: ");
                    char* end = cipher_decrypt(newCaesar, text.c_str());
                    printf(end);
                    printf("\n");
                    cipher_free(end);
                    cipher_destroy(newCaesar);
                    break;
                }
            
                default:
                    printf("Choise does not exist\n");
                    break;
            }
            break;
        }
        case 2:

        {
            std::string input_key;
            printf("Enter key:\n");
            std::cin >> input_key;
            
            cipher_t* newVigenere = cipher_create_vigenere(input_key.c_str());
            printf("Enter:\n"
                "1-Encrypt:\n"
                "2-Decrypt:\n");
            int a;
            scanf_s("%d", &a);
            switch (a)
            {
                case 1:
                {
                    std::string text;
                    printf("Enter text:\n");
                    std::cin >> text;
                    printf("Result: ");
                    char* end = cipher_encrypt(newVigenere, text.c_str());
                    printf(end);
                    printf("\n");

                    cipher_free(end);
                    cipher_destroy(newVigenere);
                    break;
                }
                case 2:
                {
                    std::string text;
                    printf("Enter text:\n");
                    std::cin >> text;
                    printf("Result: ");
                    char* end = cipher_decrypt(newVigenere, text.c_str());
                    printf(end);
                    printf("\n");

                    cipher_free(end);
                    cipher_destroy(newVigenere);
                    break;
                }

                default:
                    printf("Choise does not exist\n");
                    break;
            }
            break;
        }
        case 3:
            FreeLibrary(cipher);
            printf("Exit successful\n");
            break;
        default:
            printf("Choise does not exist\n");
            break;
        }
    }
}

