
#include "CaesarCipher.h"




std::string CaesarCipher::encrypt(const std::string& text)
{
		
	std::string newText  = text;
	for (int i = 0; i < text.length(); i++)
	{
			
		if (newText[i] >= 'a' && newText[i] <= 'z')
		{
			newText[i] = (newText[i] - 'a' + keyValue % 26 + 26) % 26 + 'a';
		}
		if (newText[i] >= 'A' && newText[i] <= 'Z')
		{
			newText[i] = (newText[i] - 'A' + keyValue % 26 + 26) % 26 + 'A';
		}
	}
	return newText;
		
}
std::string CaesarCipher::decrypt(const std::string& text)
{

	std::string newText = text;
	for (int i = 0; i < text.length(); i++)
	{

		if (newText[i] >= 'a' && newText[i] <= 'z')
		{
			newText[i] = (newText[i] - 'a' - keyValue % 26 + 26) % 26 + 'a';
		}
		if (newText[i] >= 'A' && newText[i] <= 'Z')
		{
			newText[i] = (newText[i] - 'A' - keyValue % 26 + 26) % 26 + 'A';
		}
	}
	return newText;

}