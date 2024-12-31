#include "Queue.h"

ArrayQueue::LinearQueue::LinearQueue()
{
    front_position = -1;
    rear_position = -1;
    for (int i = 0; i < QUEUE_SIZE; i++)
        array[i] = 0;
}

bool ArrayQueue::LinearQueue::isFull()
{
    return (rear_position == QUEUE_SIZE - 1) ? true : false;
}

bool ArrayQueue::LinearQueue::isEmpty()
{
    return (front_position == -1) ? true : false;
}

void ArrayQueue::LinearQueue::enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue Overflown. Couldnot enqueue the given data\n";
        return;
    }

    if (front_position == -1)
    {
        array[++rear_position] = value;
        front_position++;
    }

    else
        array[++rear_position] = value;
}

int ArrayQueue::LinearQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflown. Couldnot dequeue\n";
        return -1;
    }

    int value = 0;

    if (front_position == rear_position)
    {
        value = array[front_position];
        array[front_position] = 0;
        rear_position = -1;
        front_position = -1;
    }
    else
    {
        value = array[front_position];
        array[front_position++] = 0;
    }

    return value;
}

int ArrayQueue::LinearQueue::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing at front!" << endl;
        return -1;
    }
    return array[front_position];
}

int ArrayQueue::LinearQueue::rear()
{
    if (isEmpty())
    {
        cout<<"Queue is empty. Nothing at rear!" <<endl;
        return -1;
    }
    return array[rear_position];
    
}

int ArrayQueue::LinearQueue::count()
{
    return (isEmpty())? 0 : rear_position - front_position + 1;
}

void ArrayQueue::LinearQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue empty!" << endl;
        return;
    }

    cout << "The total number of elements in queue are: " << count() << endl
         << "The elements are: \n";
    for (size_t i = 0; i < QUEUE_SIZE; i++)
    {
        if (array[i] != 0)
        {
            cout << array[i] << " | ";
        }
    }
    cout << endl;
}