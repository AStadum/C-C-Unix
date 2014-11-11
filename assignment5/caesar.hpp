/*
** Anders Stadum
** CIS 330
** Assignment 5
** 2/11/2014
*/

#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include <string>
#include "cipher.hpp"

class CaesarCipher : public Cipher {
public:
	CaesarCipher();
	virtual ~CaesarCipher();
	virtual std::string encrypt( std::string &inputText );
	virtual std::string decrypt( std::string &inputText );
};

#endif
