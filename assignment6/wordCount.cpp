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

// #include <boost/regex.hpp>
#include "mr.hpp"
#include "ioutils.hpp"
#include "wordCount.hpp"


namespace mr {
// Map and reduce methods to count occurrences of a word in a given text.

// A specialized map function with string keys and int values
void
WordCount::MRmap(const std::map<std::string,std::string> &input,
				std::multimap<std::string,int> &out_values) {
	IOUtils io;
	// input: in a real Map Reduce application the input will also be a map
	// where the key is a file name or URL, and the value is the document's contents.
	// Here we just take the string input and process it.
	for (auto it = input.begin(); it != input.end(); it++ ) {
		std::string inputString = io.readFromFile(it->first);

		// Split up the input into words
		std::istringstream iss(inputString);
		do {
			std::string word;
			iss >> word;
			// int len = word.length();							//horrible 
			// for(int i = 0; i != len; i++)
			// {
			// 	if(word.back() == '.')
			// 		word.pop_back()
			// 	switch (word[i])
			// 	{
			// 		case ',' : word.erase(i,1);
			// 		break;
			// 		case '.' : word.erase(i,1);
			// 		break;
			// 		case '/' : word.erase(i,1);
			// 		break;
			// 		case '!' : word.erase(i,1);
			// 		break;
			// 		case ':' : word.erase(i,1);
			// 		break;
			// 		case ';' : word.erase(i,1);
			// 		break;
			// 		case '?' : word.erase(i,1);
			// 		break;
			// 		case '\"' : word.erase(i,1);
			// 		break;
			// 		case '-' : word.erase(i,1);
			// 		break;
			// 		case '_' : word.erase(i,1);
			// 		break;
			// 		default:
			// 		break;
			// 	}
			// }
			// Each word gets assigned a count of 1

			word = std::string(std::find_if(word.begin(), word.end(), std::not1(std::ptr_fun<int, int>(ispunct))),
                  std::find_if(word.rbegin(), word.rend(), std::not1(std::ptr_fun<int, int>(ispunct))).base()); //using the std library, find each punctuation and remove it

			out_values.insert(std::pair<std::string,int>(word,1)); //insert into map
			
			} while (iss);
	}
}

// A specialized reduce function with string keys and int values
void
WordCount::MRreduce(const std::multimap<std::string,int> &intermediate_values,
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
