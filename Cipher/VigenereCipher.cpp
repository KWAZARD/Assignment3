
#include "VigenereCipher.h"
#include <cctype>


std::string VigenereCipher::encrypt(const std::string& text)
{

	std::string newText = text;
	int g = 0;

	for (int i = 0; i < text.length(); i++)
	{
		char k = tolower(key_[i % key_.length()]) - 'a';
		if (newText[i] >= 'a' && newText[i] <= 'z')
		{
			char k = tolower(key_[g % key_.length()]) - 'a';
			g++;
			newText[i] = (newText[i] - 'a' + k) % 26 + 'a';
		}
		if (newText[i] >= 'A' && newText[i] <= 'Z')
		{
			char k = tolower(key_[g % key_.length()]) - 'a';
			g++;
			newText[i] = (newText[i] - 'A' + k) % 26 + 'A';
		}
	}
	return newText;

}
std::string VigenereCipher::decrypt(const std::string& text)
{

	std::string newText = text;
	int g = 0;
	for (int i = 0; i < text.length(); i++)
	{
		
		
		if (newText[i] >= 'a' && newText[i] <= 'z')
		{
			char k = tolower(key_[g % key_.length()]) - 'a';
			g++;
			newText[i] = (newText[i] - 'a' - k + 26) % 26 + 'a';
		}
		if (newText[i] >= 'A' && newText[i] <= 'Z')
		{
			char k = tolower(key_[g % key_.length()]) - 'a';
			g++;
			newText[i] = (newText[i] - 'A' - k + 26) % 26 + 'A';
		}
	}
	return newText;

}
