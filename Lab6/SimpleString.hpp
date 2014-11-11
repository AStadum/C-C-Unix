

#ifndef SIMPLESTRING_HPP_
#define SIMPLESTRING_HPP_

#include <string>

class SimpleString {
public:
	SimpleString(int length);
	SimpleString(const SimpleString &str);
	SimpleString();
	std::string getString();
	~SimpleString();

private:
	char * str;
	int length;
};

#endif