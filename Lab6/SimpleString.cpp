#include <iostream>
#include <cstring>


SimpleString::SimpleString()
{
	std::cout << "This is the default constructor" << std::endl;
}

SimpleString::SimpleString(SimpleString &str) //copy constructor
{
	std::cout << "This is the copy constructor" << std::endl;
}

SimpleString::SimpleString(char str)
{	
	int length = strlen(str);
	str = new char[length];
	for (int i = 0; i < length; ++i)
	{
		
	}
	std::cout << "this is the overloaded constructor" << std::endl;
}

SimpleString::getString()
{
	return str;
}

~SimpleString()
{
	std::cout << "Freeing memory!" << std::endl;
    delete[] str;
}