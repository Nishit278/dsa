#include <iostream>

using namespace std;

class AbstractEmployee { // this class is like a contract, like which ever class decides to inherit from this class will have to provide an implemention for this method 

    virtual void askForPromotion() = 0; // virtual class is to name a base class, then the derived class overides the data 
};
class Employee:AbstractEmployee {
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
        void askForPromotion(){
            if (Age >= 30)
                cout << Name << " is promoted."<<endl;
            else 
                cout << "sorry, you're not promoted."<<endl;
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

    Employee e2 = Employee("John Doe", "Amazon", 34);
    e.askForPromotion();
    e2.askForPromotion();

    return 0;
}