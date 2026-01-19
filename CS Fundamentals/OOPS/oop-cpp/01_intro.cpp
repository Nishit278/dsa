// Description: This program demonstrates the use of classes and objects, in CPP, this is a part of OOPS concept.

#include <iostream>
using namespace std;

class Hero
{
private:
    string name;
    int age;
    string power;

public:
    // constructor and destructor
    // static members
    static int timeToComplete;
    // static functions
    static void printTimeToComplete()
    {
        cout << "Time to complete -> " << timeToComplete << endl;
    }
    Hero()
    {
        cout << "Object created" << endl;
    }
    // Parameterized constructor
    Hero(string name, int age, string power)
    {
        cout << "this->" << this << endl;
        this->name = name;
        this->age = age;
        this->power = power;
    }

    // this keyword
    // this keyword is a pointer that points to the object that invokes the member function
    // this keyword is used to differentiate between the class members and the function parameters
    // this keyword is used to access the class members when they have the same name as the function parameters

    // copy constructor
    // A copy constructor is a member function that initializes an object using another object of the same class.
    // A copy constructor has the following general function prototype:
    // ClassName (const ClassName &old_obj);
    // The copy constructor is called when a new object is created from an existing object, as a copy of the existing object.
    // The copy constructor is used to:
    // Initialize one object from another of the same type.
    // Copy an object to pass it as an argument to a function.
    // Copy an object to return it from a function.
    // If a copy constructor is not defined in a class, the compiler itself defines one.
    // If we define a copy constructor, we must define a destructor also.

    Hero(Hero &old_obj)
    {
        cout << "Copy constructor called" << endl;
        name = old_obj.name;
        age = old_obj.age;
        power = old_obj.power;
    }
    // !Why are we passing by reference?
    // If we pass by value, a new object will be created and the copy constructor will be called again, which will create an infinite loop.

    ~Hero()
    {
        cout << "Object destroyed" << endl;
    }

    // getter and setter methods
    void setPower(string power)
    {
        this->power = power;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void getPower()
    {
        cout << power << endl;
    }
    void getAge()
    {
        cout << age << endl;
    }
    void getName()
    {
        cout << name << endl;
    }
    void introduce()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Power: " << power << endl;
    }
};

// static member initialization
int Hero::timeToComplete = 10; //! :: is used to access the static members of the class and is called the scope resolution operator

int main()
{
    // Hero hero1;              // static allocation
    // hero1.name = "Superman"; // . is used to access the members of the object
    // hero1.age = 30;
    // hero1.power = "Flying";
    // hero1.introduce();
    // Hero *hero2 = new Hero(); // dynamic allocation using new keyword
    // hero2->name = "Batman";   // -> is used to access the members of the object when using pointers
    //? (*hero2).age = 32;        // this is also valid (dereferencing the pointer and then accessing the member
    // hero2->power = "Rich";
    // hero2->introduce();
    // delete hero2; // deleting the object created using new keyword
    Hero hero3;
    hero3.setName("Batman");
    hero3.setAge(32);
    hero3.setPower("Rich");
    hero3.getName();
    hero3.introduce();

    Hero *hero4 = new Hero();
    hero4->setName("Superman");
    (*hero4).setAge(30);
    hero4->setPower("Flying");
    hero4->getPower();
    hero4->introduce();
    delete hero4;
    // Object Destroyed is printed twice because we have created two objects using new keyword and we have deleted both of them.

    Hero hero5("Wonder", 25, "Invisible");
    cout << "hero5->" << &hero5 << endl;
    hero5.introduce();
    // stores the address of the current object

    Hero hero6 = hero5;
    Hero hero7(hero5);
    cout << "hero6->" << &hero6 << endl;
    hero6.introduce();

    // Static keyword
    cout << hero7.timeToComplete << endl; // static members are accessed using the object name but it is not a good practice
    cout << Hero::timeToComplete << endl; // static members are accessed using the class name and the scope resolution operator (::)
    Hero::printTimeToComplete();          // static functions are accessed using the class name and the scope resolution operator (::)

    return 0;
}

// ** NOTES **
// 1. Classes are user-defined data types that act as the blueprint for individual objects.
// 2. Objects are instances of classes.
// 3. Classes can have data members (variables) and member functions (methods).
// 4. Whenever an object is created, the constructor is called.
// 5. Whenever an object is deleted, the destructor is called.
// 6. The constructor and destructor have the same name as the class and are identified by the absence of a return type.
// 7. The constructor is used to initialize the object.
// 8. The destructor is used to clean up the object.
// 9. The moment we write a constructor, the default constructor is not provided by the compiler.
// 10. There can me multiple constructors in a class, this is called constructor overloading.
// 11. Contructor overloading is used to create objects in different ways.

// ?DEEP vs SHALLOW COPY (in simple words)
// Shallow Copy - When we create a new object using the default copy constructor, the new object is created and the values of the old object are copied to the new object. If the old object has pointers, the new object will have the same pointers pointing to the same memory location.
// in shadlow copy the address of the pointers is copied, not the value.
// Deep Copy - When we create a new object using the custom copy constructor, the new object is created and the values of the old object are copied to the new object. If the old object has pointers, the new object will have new pointers pointing to new memory locations.
// in deep copy the value of the pointers is copied, not the address.

// !DESTRUCTOR
// 1. A destructor is a member function that is called when an object goes out of scope or is deleted.
// 2. The destructor has the same name as the class and is preceded by a tilde (~).
// 3. The destructor does not take any arguments or return any value.
// 4. The destructor is called automatically when an object is deleted or goes out of scope.
// 5. The destructor is used to clean up the object.
//* 6. The destructor is called automatically for statically allocated objects.
//* 7. The destructor is called using the delete keyword for dynamically allocated objects.

// ! STATIC KEYWORD
// 1. The static keyword is used to create class members that are shared by all objects of the class.
// 2. The static keyword is used to create class variables and class functions.
// 3. The static keyword is used to create static data members and static member functions.
// 4. Data members and functions declared as static are associated with the class, not with the objects of the class.
// !5. Static member functions can only access static data members, static member functions, and other static members.


//? Padding
// 1. Padding is the process of inserting unused memory between the members of a class to ensure that the members are properly aligned in memory.
// 2. Padding is done by the compiler to optimize the memory access of the CPU.
// 3. Padding is done to ensure that the members of the class are properly aligned in memory.

//? Greedy alignment
// 1. Greedy alignment is the process of aligning the members of a class on the largest data type in the class.
// 2. Greedy alignment is done to ensure that the members of the class are properly aligned in memory.
