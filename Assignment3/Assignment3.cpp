// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include "cipher_api.h"
#include <iostream>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


typedef cipher_t* (*cipher_create_caesar_fn)(int key);
typedef cipher_t* (*cipher_create_vigenere_fn)(const char* key);
typedef char* (*cipher_encrypt_fn)(cipher_t* cipher, const char* text);
typedef char* (*cipher_decrypt_fn)(cipher_t* cipher, const char* text);
typedef void (*cipher_destroy_fn)(cipher_t* cipher);
typedef void (*cipher_free_fn)(char* str);



int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    
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
       

        int choice;
        printf("Enter cipher:\n"
            "1- Caesar\n"
            "2- Vigenere\n"
            "3- Exit\n");
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int input_key;
            printf("Enter key in number:\n");

            std::cin >> input_key;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            cipher_t* newCaesar = cipher_create_caesar(input_key);
            printf("Enter:\n"
                "1-Encrypt:\n"
                "2-Decrypt:\n");
            int a;
            std::cin >> a;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            switch (a)
            {
                case 1:
                {
                    std::string text;
                    printf("Enter text:\n");
                    std::getline(std::cin, text);


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
                    std::getline(std::cin, text);

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
            std::cin.clear();
            std::cin.ignore(INFINITY, '\n');
            cipher_t* newVigenere = cipher_create_vigenere(input_key.c_str());
            printf("Enter:\n"
                "1-Encrypt:\n"
                "2-Decrypt:\n");
            int a;
            std::cin >> a;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            switch (a)
            {
                case 1:
                {
                    std::string text;
                    printf("Enter text:\n");
                    std::getline(std::cin, text);
                    
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
                    std::getline(std::cin, text);
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
            _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
            _CrtDumpMemoryLeaks();
            FreeLibrary(cipher);
            printf("Exit successful\n");

            
            return 0;
        default:
            printf("Choise does not exist\n");
            break;
        }
    }
}

