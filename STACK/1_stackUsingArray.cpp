#include <bits/stdc++.h>
using namespace std;




class Stack{
    public:
    int *stack;
    int top;
    int capacity;

    // construstor 
    Stack(int size){
        capacity = size;
        stack = new int[capacity];
        top = -1;

    }
    ~Stack(){
        delete[] stack;
    }

    void push(int val){
        if(isFull()){
            cout<<"Stack Overflow : Cannot push "<<val<<endl;
            return;
        }
        stack[++top]=val;
        cout<<"Pushed "<<val<<" To Stack "<<endl;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is underflow:Cannot pop "<<endl;
        }
        return stack[top--];
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return -1;
        }
        return stack[top];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top == capacity-1;
    }
    

};
int main()
{
    Stack stack(5);
    stack.push(10);
    stack.push(19);
    stack.push(17);
    cout<<"Top element is : "<<stack.peek()<<endl;

    cout << "Popped element is: " << stack.pop() << endl;
    cout << "Top element is: " << stack.peek() << endl;
    stack.pop();
    stack.pop();
    cout<<"Top element is : "<<stack.peek()<<endl;

    stack.pop(); // Trying to pop from an empty stack




    return 0;
}