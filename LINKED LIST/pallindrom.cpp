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

// Checking using stack  big of two N ,space big of n 

bool checkPallindrom(Node*&head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    stack<int>st;
    Node*temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp  = head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return false ;
            break;
        }
        else {
            temp = temp->next;
            st.pop();
        }
    }
    return true;
}

// important 
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

bool withOutextraSpace(Node*&head)
{
    if(head==NULL ||  head->next ==NULL){
        return true;
    }
    Node*slow = head;
    Node*fast  = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node*newHead = recursiveReverse(slow->next);
    Node*first = head;
    Node*second = newHead;
    while(second!=NULL){
        if(first->data !=second->data){
            recursiveReverse(newHead);
            return false;

        }
        first = first->next;
        second = second->next;
    }
    recursiveReverse(newHead);
    return true;

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
int main()
{
    vector<int> nums = {1,2,3,3,2,5};
    Node *head = convertArrLL(nums);
    printLL(head);
    cout<<"If Pallindrom then 1 otherwise  0 : "<<checkPallindrom(head)<<endl;
    cout<<"If Pallindrom then 1 otherwise  0 : "<<withOutextraSpace(head);

    return 0;
}