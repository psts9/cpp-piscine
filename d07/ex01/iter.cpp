#include <iostream>

template<typename T, typename D, typename F>
void    iter(T* p, size_t len, F (&f)(D))
{
    for (size_t i = 0; i < len; ++i)
        f(p[i]);
}

void    printInt(int n)
{
    std::cout << n << std::endl;
}

int    printStr(std::string const& str)
{
    std::cout << str << std::endl;
    return (1);
}

template<typename T>
void    multByTwo(T& d)
{
    d *= 2.0;
}

int main(void)
{
    int* arr = new int[42];

    for (int i = 0; i < 42; ++i)
        arr[i] = i;

    iter(arr, 42, printInt);

    std::cout << std::endl;

    std::string* s = new std::string[42];

    for (int i = 0; i < 42; ++i)
    {
        std::string temp;
        for (int j = 0; j < i; ++j)
            temp += "a";
        s[i] = temp;
    }

    iter(s, 42, printStr);

    std::cout << std::endl;

    double* drr = new double[21];

    for (int i = 0; i < 21; ++i)
    {
        drr[i] = static_cast<double>(i) / 2.787;
        std::cout << drr[i] << std::endl;
    }

    std::cout << std::endl;

    iter(drr, 21, multByTwo<double>);

    std::cout << std::endl;

    for (int i = 0; i < 21; ++i)
    {
        std::cout << drr[i] << std::endl;
    }

    return (0);
}
