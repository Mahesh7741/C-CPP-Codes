#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100
class Queue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else if (front == rear)
        {
            int temp = arr[front];
            front = rear = -1;
            return temp;
        }
        else
        {
            int temp = arr[front];
            front = (front + 1) % MAX_SIZE;
            return temp;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.peek() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Front element: " << queue.peek() << endl;

    return 0;
}
