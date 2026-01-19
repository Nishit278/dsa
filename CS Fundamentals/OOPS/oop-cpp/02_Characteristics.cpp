// Wrapping up data into a single unit
// 2. Encapsulation is the bundling of data with the methods that operate on that data.

#include <iostream>
#include <string>
using namespace std;

// !Access Modifiers
//  * Public - members are accessible from outside the class.
//  * Private - members cannot be accessed (or viewed) from outside the class.
//  * Protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

// * ENCAPSULATION NOTES  - (intformation hiding, data hiding)
// ?Encapsulation is the bundling of data with the methods that operate on that data.
// Encapsulation is used to hide the values or state of a structured data object inside a class, preventing unauthorized parties' direct access to them.
// Encapsulation is used to restrict direct access to some of the object's components.
// !Fully encapsulated class -> all the data members are private and can only be accessed using public methods of the class.
// Can make class read only by not providing any setter methods.
// Code resuability - can be used in other programs without any modification.

// * INHERITENCE NOTES -
// Inheritance is the mechanism by which one class acquires the properties and behavior of another class.
// ?The class that is inherited from is called the base class, and the class that inherits is called the derived class.
// Inheritance is used to create a new class that is built upon an existing class.

// * MODE OF INHERITENCE -
// Public - public members of the base class become public members of the derived class.
// Protected - protected members of the base class become protected members of the derived class.
// Private - private members of the base class become private members of the derived class.

// !Base class member access specifiers      Public     Protected       Private
// ?Public member of base class              Public     Protected       Not accessible
// ?Protected member of base class           Protected  Protected       Not accessible
// ?Private member of base class             NA         NA              NA

class Human
{ // parent class
public:
    string name;
    string gender;
    int age;
    int height;
    int weight;

    void eat()
    {
        cout << name << " is eating" << endl;
    }
    void setWeight(int w)
    {
        weight = w;
    }
};

class Male : public Human // class child_name : mode parent_name or child class_name : access_specifier parent class_name
{                         // child class
public:
    string color;
    void sleep()
    {
        cout << name << " is sleeping" << endl;
    }
};

int main()
{
    Male m1;
    m1.name = "nishit";
    m1.color = "white";
    cout << "name->" << m1.name << endl;
    cout << "weight->" << m1.weight << endl;
    cout << "color->" << m1.color << endl;
}

// Abstraction
// Abstraction is the concept of hiding the internal details and showing only the necessary details to the user.
// Abstraction can be achieved by using access specifiers (public, private, protected) in classes.
// Main difference between encapsulation and abstraction is that abstraction is achieved by using access specifiers, whereas encapsulation is achieved by using classes and objects.

// Polymorphism
// Polymorphism is the ability of a variable, function, or object to take multiple forms.
// Polymorphism is the ability to redefine methods for derived classes.
// Types of polymorphism:
// Compile time polymorphism - function overloading, operator overloading (function name is the same but the parameters are different)
// Run time polymorphism - function overriding (virtual functions)

// Virtual functions
// A virtual function is a member function in the base class that you expect to redefine in derived classes.
// When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.
// Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
// They are mainly used to achieve runtime polymorphism.
// syntax of a normal  virtual function
// virtual return_type function_name(parameters);

//? example of a normal virtual function
class Base
{
public:
    virtual void show()
    {
        cout << "Base class" << endl;
    }
};

// Pure virtual function
// A pure virtual function is a function declared in a base class that has no definition relative to the base class.
// A pure virtual function is declared by assigning 0 in the declaration.
// A class containing a pure virtual function is known as an abstract class.
// syntax of pure virtual function
// virtual return_type function_name(parameters) = 0;
// example of pure virtual function
class Base
{
public:
    virtual void show() = 0; // pure virtual function - no definition provided
};



// Types of inheritance
// Single inheritance - one class inherits from one class
// Multiple inheritance - one class inherits from multiple classes
// Multilevel inheritance - one class inherits from another class, which in turn inherits from another class
// Hierarchical inheritance - multiple classes inherit from a single class
// Hybrid inheritance - combination of multiple and multilevel inheritance

// Hidden