#include <iostream>
#include <stdexcept>

using namespace std;
//Classes and exceptions
int main() {

    class CustomException: public exception{

        private:
            string message;
        
        public:
        
        //constructor
        CustomException(const string& msg): message(msg){}

        //char pointer
        const char* what() const noexcept override{
            return message.c_str();
        };
    };

    try
    {
        throw CustomException("Custom error! ");
    }
    catch(const CustomException& e)
    {
        std::cerr << e.what() << '\n';
    }catch(const exception& e){
        cerr << "Fallback: " << e.what() << endl;
    }

    return 0;
}