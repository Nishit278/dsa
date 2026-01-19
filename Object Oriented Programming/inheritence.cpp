#include <iostream>

using namespace std;

class AbstractEmployee { 

    virtual void askForPromotion() = 0; 
};
class Employee:AbstractEmployee {
    private:
        string Company;
        int Age;
    protected: // makes Name accessible to its derived classes since they can't access it if it is in private.
        string Name;
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
class Developer : public Employee { 
    // public mode: when we want to make public members of the base class public to the derived class  
    // private mode: public and private members are private to derived class 
    // protected: both public and private members of the base class will become protected.
    public:
        string favProgrammingLanguage;
        Developer(string name, string company, int age, string language)
           :Employee(name, company, age) // to construct these three properties since they were already constructed 
            {
                favProgrammingLanguage = language;
            }
        void printDetails(){
            cout << Name << " is fixing bugs in "<<favProgrammingLanguage<< endl;
            cout << getName() << " is fixing bugs in "<<favProgrammingLanguage<< endl;
        }
};

int main(){
    Employee e = Employee("Nishit", "Google", 20);

    Employee e2 = Employee("John Doe", "Amazon", 34);
    e.askForPromotion();
    e2.askForPromotion();
    Developer d("Nishit", "Goldman sachs", 20, "C++");
    d.printDetails();
    d.askForPromotion();
    return 0;
}