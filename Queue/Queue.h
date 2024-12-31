#define QUEUE_SIZE 10
namespace ArrayQueue
{
    class LinearQueue
    {
    private:
        int front_position;
        int rear_position;
        int array[QUEUE_SIZE];

    public:
        LinearQueue();

        bool isEmpty();

        bool isFull();

        void enqueue(int value);

        int dequeue();

        int front();

        int rear();

        int count();

        void display();
    };

} // namespace ArrayQueue
