#include <iostream>

//abstract class
class Role{

    public:
        virtual double calculatePerformance() const = 0;
        virtual ~Role(){}
};

class Employee: public Role{

    private:
        double tasksCompleted;
    
    public:
        Employee(double tc): tasksCompleted(tc){}
        double calculatePerformance() const override{
            return tasksCompleted * 0.5;
        }
};

int main(){

    //Role* role = new Role();
    Role* role = new Employee(10.0);

    std::cout << "Performance Score: " << role->calculatePerformance() << std::endl;


    delete role;
    return 0;
}