#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::string;

#include "queue.h"

int displayOptions()
{
    int options;
    cout << endl
         << "--------------------------------------" << endl
         << "~~ Queue functions ~~" << endl
         << "--------------------------------------" << endl
         << "What operations do you want to choose?" << endl
         << "1. enqueue(data) - Insert a data into rear of queue" << endl
         << "2. dequeue() - Delete a data from front of queue" << endl
         << "3. isEmpty() - Check if queue is empty" << endl
         << "4. isFull() - Check if queue is full" << endl
         << "5. front() - See the front element of queue." << endl
         << "6. rear() - See the rear element of queue." << endl
         << "7. count() - Count the number of elements in queue" << endl
         << "8. display() - Display all elements of queue" << endl
         << "9. Clear Screen" << endl
         << "Enter 0 to exit. Select Option Number: " << endl;

    cin >> options;
    cout << "--------------------------------------" << endl;

    return options;
}

int main()
{
    CircularQueue *queue = new CircularQueue();
    int option, value, dequeued_element;

    do
    {
        option = displayOptions();

        switch (option) // switch case for options that are selected
        {
        case 0:
            break;

        case 1: //  Enqueue
            cout << "Enter the value to enqueue: ";
            cin >> value;

            queue->enqueue(value);
            break;

        case 2: //  Dequeue
            dequeued_element = queue->dequeue();
            (dequeued_element >= 0) ? cout << "The dequeued element is: " << dequeued_element << endl : cout << endl;
            break;

        case 3: //   isEmpty!
            queue->isEmpty() ? cout << "The queue is empty." << endl : cout << "The queue is not empty" << endl;
            break;

        case 4: //  isFull!
            queue->isFull() ? cout << "The queue is full." << endl : cout << "The queue is not full" << endl;
            break;

        case 5: // Front
            cout << "The element in front is: " << queue->front() << endl;
            break;

        case 6: // Rear
            queue->isEmpty() ? cout << "Queue is empty, nothing at rear" << endl : cout << "The element in rear is: " << queue->rear() << endl;
            break;

        case 7: //  Count
            cout << "There are " << queue->count() << " number of elements in queue" << endl;

            break;

        case 8: // Display Stack
            queue->display();
            break;

        case 9: // clear screen
            system("clear");
            break;

        default:
            cout << "Enter proper option number" << endl;
        }

    } while (option != 0);

    delete queue;
    return 0;
}