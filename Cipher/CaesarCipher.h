#pragma once
#include "Cipher.h"
#include <string>

class CaesarCipher : public Cipher {
private:
    int keyValue;
public:
    CaesarCipher(int key) : keyValue(key) {}
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};