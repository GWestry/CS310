#include <iostream>
#include <stdexcept>

int main(){
    try{
        bool condition = true;

        if(condition){
            throw std::runtime_error("Runtime error occured!");
        }else{
            throw std::out_of_range("Index out of bounds!");
        }
    }catch(const std::runtime_error& e){
          std::cerr << "Runtime error occured: " << e.what() << std::endl;
    }
    catch(const std::out_of_range& e){
          std::cerr << "Out of range error occured: " << e.what() << std::endl;
    }
    //catch(const std::exception& e){
    catch(...){
      std::cerr << "Unknown Exception occured: " << std::endl;
    }

    std::cout << "Continuing..." << std::endl;
    return 0;
}