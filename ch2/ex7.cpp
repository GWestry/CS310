#include <iostream>
#include <string>
using namespace std;
class Person{

    public:
        virtual void performTask() const {
            cout << " Handling general duties." << endl;
        }
};

class Employee: public Person{

    void performTask() const {
        cout << " Completing assigned work." << endl;
    }
};

class Manager: public Person{

    void performTask() const {
        cout << " Delegating task to team." << endl;
    }
};

class Staff : public Person{

    private:
        string name;
    public:
    Staff(string name){
        this->name = name;
    }

};
int main(){

    Person* staff[2];
    staff[0] = new Employee();
    staff[1] = new Manager();
    staff[2] = new Staff("John Smith");

    for (int i = 0; i < 3; i++){

        staff[i]->performTask();
    }

    delete staff[0];
    delete staff[1];
    delete staff[2];
    
    return 0;
}