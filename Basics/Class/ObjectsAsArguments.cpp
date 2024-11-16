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

    void changeData()
    {
        data++;
    }
};

void passByValue(Object obj)
{
    cout << "After passing object as value, ";
    obj.changeData();
    obj.displayData();
    /*
    A copy of the object is passed to the function.
    Changes made inside the function do not affect the original object.
    Default copy constructor is invoked (or custom, if defined).
    In this function, a copy of object is passed as argument
    */
}

void passByReferences(Object &obj)
{
    cout << "After passing object as references, ";
    obj.changeData();
    obj.displayData();
    /*
        The function receives a reference to the original object.
        Changes made inside the function affect the original object.
    */
}

void passByPointer(Object *obj_pointer)
{
    cout << "After passing pointer to an object as an argument, ";
    *obj_pointer = Object(30);
    obj_pointer->displayData();

    /*
        The function receives a pointer to the object.
        Can modify the original object using the pointer.
    */
}

int main()
{
    Object data(5);

    // The lines are for passByValue()
    // that passes obj as value in argument of a function.
    passByValue(data);
    data.displayData();

    data.changeData(); // data value now becomes 6;
    cout << endl;

    // The method represent passing of reference of an obj as a function arg.
    passByReferences(data);
    data.displayData();
    cout << endl;

    passByPointer(&data);
    data.displayData();

    return 0;
}