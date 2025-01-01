#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 5

class Queue
{
protected:
    int front_position;
    int rear_position;
    int array[QUEUE_SIZE];

public:
    Queue() = default;
    ~Queue() = default;

    virtual bool isEmpty() = 0;

    virtual bool isFull() = 0;

    virtual void enqueue(int value) = 0;

    virtual int dequeue() = 0;

    virtual int front() = 0;

    virtual int rear() = 0;

    virtual int count() = 0;

    virtual void display() = 0;
};

class LinearQueue : public Queue
{

public:
    LinearQueue();
    ~LinearQueue();

    bool isEmpty() override;

    bool isFull() override;

    void enqueue(int data) override;

    int dequeue() override;

    int front() override;

    int rear() override;

    int count() override;

    void display() override;
};

class CircularQueue : public Queue
{

public:
    CircularQueue();
    ~CircularQueue();

    bool isEmpty() override;

    bool isFull() override;

    void enqueue(int data) override;

    int dequeue() override;

    int front() override;

    int rear() override;

    int count() override;

    void display() override;
};

#endif