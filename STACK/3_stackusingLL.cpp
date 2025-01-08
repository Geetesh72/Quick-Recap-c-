#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    struct Node {
        int data;
        Node*next ;

    };
    Node*top;

    public:
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }

    void push(int val){
        Node*newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        
        cout<<"Pushed "<<val<<"  To stack "<<endl;

    }
    int pop(){
        if(isEmpty())
        {
           cout << "Stack Underflow: Cannot pop" << endl;
            return -1;
        }
        Node*temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    
    }
    int peek(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
     bool isEmpty() {
        return top == nullptr;
    }

    
    
};


int main(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    cout << "Popped element is: " << stack.pop() << endl;
    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop(); // Trying to pop from an empty stack

    return 0;
}