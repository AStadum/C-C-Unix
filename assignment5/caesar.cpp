/*
** Anders Stadum
** CIS 330
** Assignment 5
** 2/11/2014
*/

#include <iostream>
#include <string>
#include "caesar.hpp"
#include "cipher.hpp"

CaesarCipher::CaesarCipher() {}

CaesarCipher::~CaesarCipher(){}

std::string CaesarCipher::encrypt(std::string &inputText)
{
	std::string cc = inputText;
	std::string::size_type len = inputText.length();
	int key = 2;

	for(int i = 0; i != len; ++i)
	{
		if(cc[i] >= 'a' && cc[i] <= 'z' || cc[i] == 32)
		{
			if(cc[i] == 'y') //y values become a space
				cc[i] = 32;
			else if(cc[i] == 'z') //z values wrap around to become an a
				cc[i] = 'a';
			else if(cc[i] == 32) //space values become a b
				cc[i] = 'b';
			else
				cc[i] += key; //iterature through the use of our key
		}
	}
	return cc;
}

std::string CaesarCipher::decrypt(std::string &inputText)
{
	std::string dc = inputText;
	std::string::size_type len = dc.length();
	int key = 2;
	for(int i = 0; i != len; ++i)
	{
		if(dc[i] >= 'a' && dc[i] <= 'z' || dc[i] == 32) //reverse the logic
		{
			if(dc[i] == 32)
				dc[i] = 'y';
			else if(dc[i] == 'a')
				dc[i] = 'z';
			else if(dc[i] == 'b')
				dc[i] = 32;
			else
				dc[i] -= key;
		}
	}
	return dc;
}