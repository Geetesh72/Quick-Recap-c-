#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
Node *convertArrLL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *mover = head;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(nums[i]);
        mover->next = temp;
        mover = mover->next;
        // mover = temp;  both are the same thing
    }
    return head;
}

void printLL(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}
// logic to this question 
Node*reverseLL(Node*&head){
    if(head==NULL || head->next ==NULL)
    {
        return head;
    }
    Node*temp = head;
    Node*prev = NULL;
    while(temp!=NULL){
        Node*front = temp->next;
        temp->next  = prev;
        prev = temp;
        temp = front;
    }
    return prev;

}

Node*addOneToEachNode(Node*&head){
    // if(head == NULL || head->next==NULL){
    //     if(head->data<9){
    //         head->data = head->data+1;
    //         return head;

    //     }
    //     else {
    //         Node*newNode = new Node(head->data)
    //     }
    // }

    head = reverseLL(head);
    Node*temp = head;
    int carry =1;
    while(temp!=NULL){
        temp->data = temp->data+1;
        if(temp->data<10){
            carry =0;
            break;
        }
        else{
            temp->data = 0; /// suppose if 9 
            carry  = 1;
        }
        temp = temp->next;
    }
    if(carry){
        Node*newNode = new Node(carry);
        head = reverseLL(head);
        newNode ->next = head;
        return newNode;
    }
    head = reverseLL(head); // big of 3n 
    return head;
}
int main()
{
    vector<int> nums = {1,5,9,7,8};
    Node *head = convertArrLL(nums);
    printLL(head);
    head = reverseLL(head);
    printLL(head);

    return 0;
}