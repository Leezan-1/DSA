#include <iostream>
#include "../Stack/Stack.cpp"

#define TOWER_HEIGHT 1

using namespace std;
stackk::Stack tower1, tower2, tower3;



void displayTower() // displays the tower of hanoi
{
    cout << "The tower of hanoi is: " << endl;
    for (size_t i = 0; i < TOWER_HEIGHT; i++)
    {
        cout << " ___\t ___\t ___" << endl
             << "| " << tower1.peek(i) << " |\t| "
             << tower2.peek(i) << " |\t| "
             << tower3.peek(i) << " |" << endl;
    }
    cout << endl;
}

int main()
{
    // inserting disks in hanoi
    for (size_t i = 1; i <= TOWER_HEIGHT; i++)
    {
        tower1.push(i);
    }
    displayTower();

    displayTower();
    return 0;
}