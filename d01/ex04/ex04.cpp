#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string* strPtr = &str;
	std::string& strRef = str;

	std::cout << "Original string: " << str << std::endl;
	std::cout << "Pointer to string: " << *strPtr << std::endl;
	std::cout << "Reference to string: " << strRef << std::endl;

	return (0);
}
