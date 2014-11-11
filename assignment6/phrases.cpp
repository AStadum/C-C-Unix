/*
Anders Stadum
CIS 330 Assignment 6
*/

#include <sstream>     	// std::istringstream
#include <fstream>
#include <iostream>
#include <map>			// std::multimap
#include <algorithm>   	// std::copy, std::for_each
#include <locale> 
#include <string>

#include "mr.hpp"
#include "ioutils.hpp"
#include "phrases.hpp"


namespace mr {
// Map and reduce methods to count occurrences of a word in a given text.

// A specialized map function with string keys and int values
void
Phrases::MRmap(const std::map<std::string,std::string> &input,
				std::multimap<std::string,int> &out_values) {
	IOUtils io;
	// input: in a real Map Reduce application the input will also be a map
	// where the key is a file name or URL, and the value is the document's contents.
	// Here we just take the string input and process it.
	for (auto it = input.begin(); it != input.end(); it++ ) {
		std::string inputString = io.readFromFile(it->first);

		// Split up the input into words
		std::istringstream iss(inputString);

		std::string word;
		std::string word2;
		iss >> word; //read in file
		word.append(" "); //store each word after each space

		do {
			iss >> word2;
			word.append(word2);

			word2 = std::string(std::find_if(word2.begin(), word2.end(), std::not1(std::ptr_fun<int, int>(ispunct))),
                  std::find_if(word2.rbegin(), word2.rend(), std::not1(std::ptr_fun<int, int>(ispunct))).base()); //remove puncts
			
			word.erase(std::find_if(word.rbegin(), word.rend(), 
                       std::not1(std::ptr_fun<int, int>(std::isspace))).base(), word.end());

			out_values.insert(std::pair<std::string,int>(word,1)); //insert into map

			//word.clear();

			word2.append(" ");
			word = word2;
	
			} while (!iss.eof());
	}
}

// A specialized reduce function with string keys and int values
void
Phrases::MRreduce(const std::multimap<std::string,int> &intermediate_values,
					std::map<std::string,int> &out_values) {

	// Sum up the counts for all intermediate_values with the same key
	// The result is the out_values map with each unique word as
	// the key and a total count of occurrences of that word as the value.
	std::for_each(intermediate_values.begin(), intermediate_values.end(),
			// Anonymous function that increments the sum for each unique key (word)
			[&](std::pair<std::string,int> mapElement)->void
			{
				out_values[mapElement.first] += 1;
			});  // end of for_each
	}
}; // namespace mr
