#include <iostream>

int main()
{
    int array[1] = {1};
    std::string Address = "calle de Madrid";
    int a = 67;
    std:: string *pAddress = &Address;
    std::cout << *pAddress;
    std::cout << *array;
    return 0;
}