#include <iostream>
#include <string>

#include "Array.hpp"

int main(void)
{
    Array<int> arr;

    std::cout << arr.size() << std::endl;

    try
    {
        std::cout << arr[0] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Array<std::string> strr(3);

    strr[0] = "Hello";
    strr[1] = ", world";
    strr[2] = "!";

    std::cout << strr[0] << strr[1] << strr[2] << std::endl;

 //   arr = strr;

    Array<int> arr2(10);

    for (int i = 0; i < arr2.size(); ++i)
        arr2[i] = i;

    arr = arr2;

    arr2[5] = 42;

    for (int i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << std::endl;

    std::cout << std::endl;
    
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << std::endl;

    return (0);
}
