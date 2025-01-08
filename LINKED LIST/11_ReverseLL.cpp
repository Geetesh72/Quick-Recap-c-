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
// using stack tc O(2N ) Along with space 
Node*reversingUsingStack(Node*&head){
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    stack<int>st;
    Node*temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data  = st.top();
        st.pop();
        temp =temp->next;
    }
    return head;

}
// changing the link  - O --> O --> O --> O --> O this is new head 
Node*reversingItrative(Node*&head){
    if(head == NULL || head->next==NULL){
        return NULL;
    }
    Node*temp = head;
    Node*prev = NULL;
    while(temp!=NULL){
        Node*front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;

    }
    return prev;
}

// Now Recursive 
Node*recursiveReverse(Node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*newhead = recursiveReverse(head->next);
    Node*front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead; 
//    tc O(n)
      // sc recursive stack space 
}





void printLL(Node *head){
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int main()
{
    vector<int> nums = {3, 5,4,58,8,9,6};
    Node *head = convertArrLL(nums);
    Node*testHead  = head;
    printLL(head);
    head = reversingUsingStack(head);
    printLL(head);
    head = reversingItrative(head);
    printLL(head);
    head = recursiveReverse(head);
    printLL(head);
    head = recursiveReverse(head);
    printLL(head);


    return 0;
}