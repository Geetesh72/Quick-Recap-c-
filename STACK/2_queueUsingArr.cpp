#include <bits/stdc++.h>
using namespace std;


class Queue{
    private:
    int *queue;
    int front,rear,capacity;
    public:
    Queue(int size){
        capacity = size;
        queue = new int[capacity];
        front =-1;
        rear  = -1;


    }
    ~Queue(){
        delete[] queue;
    }

    // enqueue 
    void enqueue(int val){
        if(isFull()){
            cout<<"Queue Overflow:cannot enqueue "<<val<<endl;
            return;
        }
        rear = (rear+1)%capacity;
        queue[rear] = val;
        if(front ==-1){
            front= rear;
        }
        cout<<"Enqueued "<<val<<endl;
    }
    // dequeue
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow : Cannot dequeued "<<endl;
            return -1;
        }
        int val  = queue[front];
        if(front == rear){
            front = -1;
            rear  =-1;
        }else{
            front = (front+1)%capacity;
        }
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};
int main()
{
    Queue q(5); // Create a queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Front element: " << q.peek() << endl; // 20
    q.enqueue(50);
    q.enqueue(60); // Queue is full
    cout << "Dequeued: " << q.dequeue() << endl; // 20
    q.enqueue(70); // Wrap around
    cout << "Front element: " << q.peek() << endl; // 30
    return 0;
}