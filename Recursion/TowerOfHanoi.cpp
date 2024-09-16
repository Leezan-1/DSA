#include <iostream>
#include "../Stack/Stack.cpp"

#define TOWER_HEIGHT 2

using namespace std;
stackk::Stack tower1, tower2, tower3;

void move_disk(int from_tower, int to_tower)
{
    int disk;

    switch (from_tower)
    {
    case 1:
        disk = tower1.pop();
        break;
    case 2:
        disk = tower2.pop();
        break;
    case 3:
        disk = tower3.pop();
        break;
    default:
        throw invalid_argument("invalid tower");
    }

    switch (to_tower)
    {
    case 1:
        tower1.push(disk);
        break;
    case 2:
        tower2.push(disk);
        break;
    case 3:
        tower3.push(disk);
        break;
    default:
        throw invalid_argument("invalid tower");
    }


    cout << "Tower " << from_tower << " --> Tower " << to_tower << endl;
}

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
    move_disk(1, 3);
    displayTower();
    return 0;
}