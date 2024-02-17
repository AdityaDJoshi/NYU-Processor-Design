#include <iostream>
#include "name.hpp"

int main() {
    std::string name = askName();
    // std::string name = "Adi";
    std::cout << "Hello " << name << "!" << std::endl;
    return 0;
}