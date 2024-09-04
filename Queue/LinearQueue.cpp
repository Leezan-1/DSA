#include <iostream>

#define QUEUE_SIZE 10

using namespace std;

class LinearQueue
{
private:
    int front_position;
    int rear_position;
    int queue_array[QUEUE_SIZE];

public:
    LinearQueue()
    {
        front_position = -1;
        rear_position = -1;

        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            queue_array[i] = 0;
        }
    }

    bool isEmpty()
    {
        return (front_position == -1 && rear_position == -1) ? true : false;
    }

    bool isFull()
    {
        return (rear_position == QUEUE_SIZE - 1) ? true : false;
    }

    int enqueue(int val)
    {
        if (isFull())
        {
            cout << "The queue is overflown" << endl;
            return -1;
        }
        else if (isEmpty())
        {
            front_position++;
        }

        rear_position++;
        queue_array[rear_position] = val;
        return rear_position;
    }

    int dequeue()
    {
        int temp = queue_array[front_position];
        if (isEmpty())
        {
            cout << "The queue is underflown" << endl;
            return -1;
        }
        else if (rear_position == front_position)
        {
            queue_array[front_position] = 0;
            front_position = rear_position = -1;
        }
        else
        {
            queue_array[front_position] = 0;
            front_position++;
        }
        return temp;
    }

    int front()
    {
        return queue_array[front_position];
    }

    int rear()
    {
        return queue_array[rear_position];
    }

    int count()
    {
        return (rear_position - front_position) + 1;
    }

    void display()
    {
        cout << "All elements in queue are: ";
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            cout << "|\t" << queue_array[i] << "\t";
        }
        cout << "|" << endl;
    }

};


int displayOptions()
{
    int options;
    cout << endl
         << "What operations do you want to choose?" << endl
         << "1. Enqueue" << endl
         << "2. Dequeue" << endl
         << "3. isEmpty()" << endl
         << "4. isFull()" << endl
         << "5. front()" << endl
         << "6. rear()" << endl
         << "7. count()" << endl
         << "8. display()" << endl
         << "9. Clear Screen" << endl
         << "Enter 0 to exit. Select Option Number: ";
    cin >> options;
    cout << endl;
    return options;
}

int main()
{
    LinearQueue queue1;
    int option, position, value, enqueue_position, dequeued_element;

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
            enqueue_position = queue1.enqueue(value);
            (enqueue_position >= 0) ? cout << "The position that value is enqueued at: " << enqueue_position << endl : cout << endl;
            break;

        case 2: //  Dequeue
            dequeued_element = queue1.dequeue();
            (dequeued_element >= 0) ? cout << "The dequeued element is: " << dequeued_element << endl : cout << endl;
            break;

        case 3: //   isEmpty!
            queue1.isEmpty() ? cout << "The queue is empty." << endl : cout << "The queue is not empty" << endl;
            break;

        case 4: //  isFull!
            queue1.isFull() ? cout << "The queue is full." << endl : cout << "The queue is not full" << endl;
            break;

        case 5: // Front
            queue1.isEmpty() ? cout << "Queue is empty, nothing at front" << endl : cout << "The element in front is: " << queue1.front() << endl;

            break;

        case 6: // Rear
            queue1.isEmpty() ? cout << "Queue is empty, nothing at rear" << endl : cout << "The element in rear is: " << queue1.rear() << endl;
            break;

        case 7: //  Count
            cout << "There are " << queue1.count() << " number of elements in queue" << endl;

            break;

        case 8: // Display Stack
            queue1.display();
            break;

        case 9: // clear screen
            system("clear");
            break;

        default:
            cout << "Enter proper option number" << endl;
        }

    } while (option != 0);

    return 0;
}
