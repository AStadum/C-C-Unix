/*
 * ioutils.hpp
 *
 *  Created on: Feb 2, 2014
 *      Author: norris
 */

#ifndef IOUTILS_HPP_
#define IOUTILS_HPP_

#include <fstream>
#include <iostream>
#include <string>

class IOUtils {
public:
	IOUtils();
	virtual ~IOUtils();
	void openStream(int argc, const char *argv[]);
	void closeStream();
	std::string readFromStream();
	std::istream getStream();
private:
	bool isFile;
	std::istream *inputStream;
};

#endif /* IOUTILS_HPP_ */
