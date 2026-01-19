#include <iostream>

using namespace std;

class Employee {
    private:
        string Name;
        string Company;
        int Age;
    public:
        Employee(string name, string company, int age){
            Name = name;
            Company = company;
            Age = age;
        }
        string getName(){ //getter
            return Name;
        }
        void setName(string name){ //setter 
            Name = name;
        }
        string getCompany(){
            return Company;
        }
        void setCompany(string company){
            Company = company;
        }
        int getAge(){
            return Age;
        }
        void setAge(int age){
            Age = age;
        }
        int introduceYourSelf(){
            cout << "Name- "<<Name<<endl;
            cout << "Age- "<< Age <<endl;
            cout << "work for- "<<Company<<endl;
            return 0;
        }

        
};

int main(){
    Employee e = Employee("Nishit", "Google", 20);
    // e.Name = "Nishit";
    // e.Age = 20;
    // e.Company = "work from home";
    e.introduceYourSelf();
    // now to create another user

    Employee e2 = Employee("John Doe", "Amazon", 26);
    // e2.Name = "John Doe";
    // e2.Age = 25;
    // e2.Company = "Goldman Sachs";
    e2.introduceYourSelf();
    e.setName("Nishit Bansal");
    e.setAge(23);
    cout << e.getName() << " is "<< e.getAge()<< " years old "<< endl;
    // now suppose we have want to create 100 more such employes 
    // creating them like this is so hectic 
    // this can be optimally achieved using a constructor 

    return 0;
}