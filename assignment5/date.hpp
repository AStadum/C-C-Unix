/*
** Anders Stadum
** CIS 330
** Assignment 5
** 2/11/2014
*/

#ifndef DATE_HPP_
#define DATE_HPP_

#include <string>
#include "cipher.hpp"

class Date : public Cipher {
public:
	Date();
	virtual ~Date();
	virtual std::string encrypt(std::string &inputText);
	virtual std::string decrypt(std::string &inputText);

private: 
	std::string date;s 
	std::string cc;
};

#endif