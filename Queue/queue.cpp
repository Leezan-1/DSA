#include "queue.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::string;

// Implementation of Linear Queue.

// linear queue initalizer
LinearQueue::LinearQueue()
{
    front_position = -1;
    rear_position = -1;
    for (int i = 0; i < QUEUE_SIZE; i++)
        array[i] = 0;
};
LinearQueue::~LinearQueue()
{
    front_position = -1;
    rear_position = -1;
    for (int i = 0; i < QUEUE_SIZE; i++)
        array[i] = 0;
};

// returns true if linear queue is full else false
bool LinearQueue::isFull()
{
    return (rear_position == QUEUE_SIZE - 1) ? true : false;
}

// returns true if linear queue is empty
bool LinearQueue::isEmpty()
{
    return (front_position == -1) ? true : false;
}

// inserts value at rear position of queue
void LinearQueue::enqueue(int value)
{
    if (isFull())
    {
        cout << " Queue Overflown. Couldnot enqueue the given data" << endl;
        return;
    }

    if (front_position == -1)
        front_position++;

    array[++rear_position] = value;

    cout << "Data enqueued successfully" << endl;
}

int LinearQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflown. Couldnot dequeue" << endl;
        return -1;
    }

    int value = 0;
    value = array[front_position];
    array[front_position++] = 0;

    if (front_position == rear_position)
        rear_position = front_position = -1;

    return value;
}

int LinearQueue::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing at front!" << endl;
        return -1;
    }
    return array[front_position];
}

int LinearQueue::rear()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing at rear!" << endl;
        return -1;
    }
    return array[rear_position];
}

int LinearQueue::count()
{
    return (isEmpty()) ? 0 : rear_position - front_position + 1;
}

void LinearQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue empty!" << endl;
        return;
    }

    cout << "The total number of elements in queue are: " << count() << endl
         << "The elements are: " << endl;

    for (int i = front_position; i <= rear_position; i++)
        cout << array[i] << " | ";

    cout << endl;
}

// Implementation of Circular Queue

CircularQueue::CircularQueue()
{
    front_position = -1;
    rear_position = -1;
    for (size_t i = 0; i < QUEUE_SIZE; i++)
        array[i] = 0;
}
CircularQueue::~CircularQueue()
{
    front_position = -1;
    rear_position = -1;
    for (size_t i = 0; i < QUEUE_SIZE; i++)
    {
        array[i] = 0;
    }
}

bool CircularQueue::isEmpty()
{
    return (front_position == -1 && rear_position == -1) ? true : false;
}

bool CircularQueue::isFull()
{
    return ((rear_position + 1) % QUEUE_SIZE == front_position) ? true : false;
}

void CircularQueue::enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue Overflown. Couldnot enqueue the given data" << endl;
        return;
    }

    rear_position = (rear_position + 1) % QUEUE_SIZE;
    array[rear_position] = data;

    if (front_position == -1)
        front_position++;

    cout << "Data enqueued successfully." << endl;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflown. Couldnot dequeue" << endl;
        return -1;
    }

    int value = array[front_position];
    array[front_position] = 0;

    if (front_position == rear_position)
        rear_position = front_position = -1;
    else
        front_position = (front_position + 1) % QUEUE_SIZE;

    return value;
}

int CircularQueue::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing at front!" << endl;
        return -1;
    }
    return array[front_position];
}

int CircularQueue::rear()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing at rear!" << endl;
        return -1;
    }
    return array[rear_position];
}

int CircularQueue::count()
{
    return (isEmpty()) ? 0 : (rear_position < front_position) ? QUEUE_SIZE - front_position + rear_position + 1
                                                              : rear_position - front_position + 1;
}

void CircularQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue empty!" << endl;
        return;
    }

    cout << "The total number of elements in queue are: " << count() << endl
         << "The elements are: " << endl;

    for (int i = front_position; i != rear_position; i = (i + 1) % QUEUE_SIZE)
        cout << array[i] << " | ";
    cout << array[rear_position];
    cout << endl;
}