#pragma once
#include "Cipher.h"
#include <string>

class VigenereCipher : public Cipher {
private:
    std::string key_;
public:
    VigenereCipher(const std::string& key) : key_(key) {}
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};