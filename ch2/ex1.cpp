#include <iostream>

int main()
{
    try{
        throw 42; // throw an int exception
    }catch(int e){
        std::cerr<< "Caught integer exception: "<< e <<std::endl;
    }
    std::cout << "Program continues..." << std:: endl;
    return 0;
}