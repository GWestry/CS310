#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
    try{
        
        try{
            //throw invalid_argument("Invalid Arg from inner block!");
            throw runtime_error("Inner Try Block Exception!");
        }catch(const runtime_error& e){
            cerr << " Inner catch: " << e.what() << endl;

        }
    }catch(const exception& e){
       cerr << " Final handler: " << e.what() << endl;
    }
    return 0;
}