#include <iostream>
#include <string>
using namespace std;

/*Review on classes/OOP*/
class Person{
    private:
        string name;
        int age;
    public:
        Person(){
            name = "";
            age = 0;
            cout << "Person constructor!" << endl;
        }

        Person(string n, int a):name(n), age(a){}

        void setName(string n){
            name = n;
        }

        string getName() const{
            return name;
        }

        void display() const{
            cout << "Name " << name << ", Age: " << age << endl;
        }

        void introduce() const{
            cout << "I am a person." << endl;
        }

};

class Employee: public Person{

    public:

        Employee(){
            cout << "Employee constructor!" << endl;
        }
        void work() const{
            cout << " Performing tasks." << endl;
        }
};

class Manager : public Employee{
    public:
        Manager(){
            cout << "Manager constructor!" << endl;
        }
};

class TaskManager {
    
    public:
        void assignTask(string taskName){
            cout << "Assigned " << taskName << endl;
        }

        void assignTask(string taskName, int priority){
            cout << "Assigned " << taskName << "(Priority: " << priority << ")" << endl;
        }

        void assignTask(string taskName, int priority, string deadline){
            cout << "Assigned " << taskName << "(Priority: " << priority << ")" << ", Due: " << deadline << endl;
        }
};
int main(){

    // Person employee("Alice", 30);
    // employee.display();
    // employee.setName("Alicia");
    // cout << "New name: " << employee.getName() << endl;

    // Employee staff;
    // staff.introduce();
    // staff.work();
    // staff.display();

    //Manager lead;

    TaskManager tm;

    tm.assignTask("Monthly Report");
    tm.assignTask("Weekly Report", 1);
    tm.assignTask("Annual Budget", 5, "End of Week");

    return 0;
}