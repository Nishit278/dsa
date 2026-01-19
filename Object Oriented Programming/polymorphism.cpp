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
        virtual void work(){
            cout << Name << "is checking mails, working on backlogs"<< endl;
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
        void work(){
            cout << Name << " is coding in "<< favProgrammingLanguage<< endl;
        }
};
class Teacher : public Employee { 
    // public mode: when we want to make public members of the base class public to the derived class  
    // private mode: public and private members are private to derived class 
    // protected: both public and private members of the base class will become protected.
    public:
        string Subject;
        Teacher(string name, string company, int age, string subject)
           :Employee(name, company, age) // to construct these three properties since they were already constructed 
            {
                Subject = subject;
            }
        void printDetails(){
            cout << Name << " is a "<<Subject << " teacher"<< endl;
            
        }
        void work(){
            cout << Name << " is teaching "<<Subject<< endl;
        }
};

int main(){
   
    Developer d("Nishit", "Goldman sachs", 20, "C++");
    d.printDetails();
    d.askForPromotion();
    d.work();
    Teacher t("Sam", "Oxford", 30, "Physics");
    t.printDetails();
    t.work();
    // we have multiple instances of the method work, for different derived classes 
    // another way to implement this is 
    cout << "implementation using pointers"<< endl;
    Employee* e1 = &t;
    Employee* e2 = &d;
    e2->work();
    e1->work();
    // adding virtual infront of the work function in the parent class means that its gonna check if there's an implementation of this function in the derived classes and if there is one it will use that one 

    return 0;
}