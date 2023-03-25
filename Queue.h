#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template <class T>
class Queue
{
    private:
        T *arr;
        int size;
        int front;
        int rear;
    public:
        Queue(int s)
        {
            size = s;
            arr = new T[size];
            front = -1;
            rear = -1;
        }
        void push(T x)
        {
            if(rear == size - 1)
            {
                cout << "Queue is full" << endl;
            }
            else if(front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                arr[rear] = x;
            }
            else
            {
                rear++;
                arr[rear] = x;
            }
        }
        void pop()
        {
            if(front == -1 && rear == -1)
            {
                cout << "Queue is empty" << endl;
            }
            else if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
        }
        T getFront()
        {
            return arr[front];
        }
        T getRear()
        {
            return arr[rear];
        }
        bool isEmpty()
        {
            if(front == -1 && rear == -1)
            {
                return true;
            }
            return false;
        }
};
