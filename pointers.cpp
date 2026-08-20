#include <iostream>

int main()
{
    int *pointer = nullptr;
    int x = 67;

    pointer = &x;

    if (pointer == nullptr){
        std::cout << "The value wasn't asigned to pointer\n"; 
    } else{
        std::cout << "The value was successfully asigned to pointer\n";
    }
    std::cout << *pointer;
    return 0;
}