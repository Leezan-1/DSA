#include <iostream>
using namespace std;

class Object
{
private:
    int data;

public:
    Object(int d) : data(d) {}

    void displayData()
    {
        cout << "Data is: " << data << endl;
    }
};

Object returnByValue()
{

    cout << "After returning object as value, ";
    return Object(30);
    // a random object is created and its copy is passed to obj3;
    // The object is deleted after the end of scope of function;
    /*
        A copy of the object is returned.
        The copy constructor is invoked unless optimized by return value optimization (RVO).
        Suitable when the returned object is a temporary result.
        Can be less efficient for large objects due to the copy overhead (though modern compilers often optimize this with RVO).
    */
}

Object &returnByReferences()
{
    cout << "After returning object as reference, ";
    static Object obj(40); // Static object persists for the program's lifetime
    return obj;

    /*
        Returning objects by reference is generally done when you want to refer to an existing,
        valid object that has a well-defined lifetime (e.g., a static object, an object passed
        to the function by reference, or a member of a class).
        A temporary object does not fit this criterion.
        Returning a reference to a temporary object is unsafe because the
        temporary object will be destroyed, leading to undefined behavior.
        Always consider the object's lifetime when returning by reference.
    */
}

int main()
{
    Object obj1 = returnByValue();
    cout << "obj1, ";
    obj1.displayData();
    cout << endl;

    Object obj2 = returnByReferences();
    cout << "obj2, ";
    obj2.displayData();
    cout << endl;
    return 0;
}