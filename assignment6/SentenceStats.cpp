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
#include "SentenceStats.hpp"


namespace mr {
// Map and reduce methods to count occurrences of a word in a given text.

// A specialized map function with string keys and int values
void
SentenceStats::MRmap(const std::map<std::string,std::string> &input,
				std::multimap<std::string,int> &out_values) {
	IOUtils io;
	// input: in a real Map Reduce application the input will also be a map
	// where the key is a file name or URL, and the value is the document's contents.
	// Here we just take the string input and process it.
	for (auto it = input.begin(); it != input.end(); it++ ) {
		std::string inputString = io.readFromFile(it->first);

		// Split up the input into words
		std::string mySentence;
		std::istringstream iss(inputString);
		int sentenceAdded = 0;
		do {
			std::string word;
			iss >> word;
			word.append(" "); //save each word into sentence after a space occurs
			mySentence.append(word);
			++sentenceAdded;     //build sentence


			if(mySentence[mySentence.length() - 2] == '.' || mySentence[mySentence.length() - 2] == '!' || mySentence[mySentence.length() - 2] == '?') //check for sentence ending punctuations
			{
				out_values.insert(std::pair<std::string,int>(mySentence,sentenceAdded)); //add strings into map
				mySentence.clear(); //clear current sentence for new sentence as we iterate through the file.
				sentenceAdded = 0; //zero out sentence word counter
			}
			
			} while (iss);
	}
}

// A specialized reduce function with string keys and int values
void
SentenceStats::MRreduce(const std::multimap<std::string,int> &intermediate_values,
					std::map<std::string,int> &out_values) {
	int maxSentence = 1;
	int minSentence = 1000;
	float aveSentence = 0;
	int count = 0;

	// Sum up the counts for all intermediate_values with the same key
	// The result is the out_values map with each unique word as
	// the key and a total count of occurrences of that word as the value.
	std::for_each(intermediate_values.begin(), intermediate_values.end(),
			// Anonymous function that increments the sum for each unique key (word)
			[&](std::pair<std::string,int> mapElement)->void
			{
				out_values[mapElement.first] = mapElement.second;

				if(mapElement.second < minSentence) // if the minimum sentence is greater than any sentence stored in the map
				{
					minSentence = mapElement.second; // set it equal to the min
				}

				if(mapElement.second > maxSentence) // if the maximum sentence is less than any sentence stored in the map
				{
					maxSentence = mapElement.second;// set it equal to the max

				}
				aveSentence += mapElement.second; //add all the sentences, then we'll compute the average in the next step.
				count++;
			});  // end of for_each
	if(aveSentence != 0)
	{
		aveSentence /= count; //take the actual average

		std::cout << "Max Sentence: " << maxSentence << std::endl;
		std::cout << "Min Sentence: " << minSentence << std::endl;
		std::cout << "Ave Sentence: " << aveSentence << std::endl;
	}
}
}; // namespace mr
