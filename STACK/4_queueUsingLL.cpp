#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    // Node structure for linked list
    struct Node {
        int data;
        Node* next;
    };

    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void enqueue(int val){
        Node*newNode = new Node();
        newNode->data = val;
        newNode ->next = nullptr;

        if(isEmpty()){
            front = rear = newNode;

        }else{
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << val << endl;
    }

    int dequeue(){
        if (isEmpty()) {
            cout << "Queue Underflow: Cannot dequeue" << endl;
            return -1;
        }
        Node*temp = front;
        int val = temp->data;
        front = front->next;

        if(front==NULL){
            rear =nullptr;
        }
        delete temp;
        return val;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

};




int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element is: " << queue.peek() << endl;

    cout << "Dequeued element is: " << queue.dequeue() << endl;
    cout << "Front element is: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // T
    return 0;
}