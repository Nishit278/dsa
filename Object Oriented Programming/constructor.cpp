#include <iostream>

using namespace std;

class Employee {
    public:
    string Name;
    string Company;
    int Age;

    int introduceYourSelf(){
        cout << "Name- "<<Name<<endl;
        cout << "Age- "<< Age <<endl;
        cout << "work for- "<<Company<<endl;
        return 0;

    }
    Employee(){
       cout << "default constructor"<<endl;
    }
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
};

int main(){
    Employee e = Employee("Nishit", "Google", 20);
    // e.Name = "Nishit";
    // e.Age = 20;
    // e.Company = "work from home";
    e.introduceYourSelf();
    // now to create another user

    Employee e2("John Doe", "Amazon", 26); // 2nd syntax to access the constructor 
    // e2.Name = "John Doe";
    // e2.Age = 25;
    // e2.Company = "Goldman Sachs";
    e2.introduceYourSelf();
    Employee e3;

    // now suppose we have want to create 100 more such employes 
    // creating them like this is so hectic 
    // this can be optimally achieved using a constructor 

    return 0;
}