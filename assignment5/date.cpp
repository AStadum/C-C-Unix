/*
** Anders Stadum
** CIS 330
** Assignment 5
** 2/11/2014
*/


#include <iostream>
#include <string>
#include "date.hpp"
#include "cipher.hpp"

Date::Date(): cc("") {}

Date::~Date(){}

std::string Date::encrypt(std::string &inputText)
{
	std::string pp = inputText;
	std::string::size_type inputLen = inputText.length(); //length of the string inputted by the 
	
	std::string date = "12/18/46";
	this->date = date; //points to private data type date.
	std::string delimiter = "/"; //remove this thingy
	size_t pos = 0; //Start at beginning of string array
	std::string token;
	while ((pos = date.find(delimiter)) != std::string::npos) //find the delimiter
	{
	    token += date.substr(0, pos); //traverse through string array
	    date.erase(0, pos + 1); //delete delimiter
	}	
	std::string parsed = token + date;			  //Suming the day and month, with the year to give us a 6 values in our string array

	int j = 0;
	for(int i = 0; i != inputLen-2; ++i) //newline char and ctrl d.
	{
		if(cc[i] != ' ') //if there is no space
			cc[i] = parsed[(i - j) % 6]; //subtract the spaces and wrap the array
		if(cc[i] == ' ')
			j++; //space counter
	}

	for(int i = 0; i != inputLen-2; ++i)
	{
		if(pp[i] != ' '){
			if(pp[i] >= 'a' && pp[i] <= 'z')
				pp[i] = (((pp[i] - 'a') + (cc[i] - '0')+26)%26 + 'a'); //lowerspace encrypt
			if(pp[i] >= 'A' && pp[i] <= 'Z')
				pp[i] = (((pp[i] - 'A') + (cc[i] - '0')+26)%26 + 'A'); //upperspace encrypt
		}
	}
	return pp;
}

std::string Date::decrypt(std::string &text)
{
	std::string dd = text;
	std::string::size_type inputLen = text.length();

	for(int i = 0; i != inputLen-2; ++i)
	{
		if(dd[i] != ' ')
		{
			if(dd[i] >= 'a' && dd[i] <= 'z')
				dd[i] = (((dd[i] - 'a') - (cc[i] - '0')+26)%26 + 'a'); //reverse the logic
			if(dd[i] >= 'A' && dd[i] <= 'Z')
				dd[i] = (((dd[i] - 'A') - (cc[i] - '0')+26)%26 + 'A');
		}
	}
	return dd;
}