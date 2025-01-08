#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};
Node *doublyList(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *prev = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        temp->back = prev;
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

// Reverse Double Linlist ; we can do it by using stack couse lifo 
 /*

      back <--O-->  next
       
 */
Node*reverseList(Node*head){
    if(head==NULL || head->next==NULL){
        return head;

    }
    Node*last= NULL;
    Node*curr = head;
    while(curr!=NULL){
        last = curr->back;
        curr->back = curr->next;
        curr->next = last;
        curr=curr->back; // current's back  = currect next 

    }
    return last->back;

}

void printLL(Node*head)
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
    vector<int> nums = {48, 2, 41, 2, 4, 8, 9, 3, 2};
    Node *head = doublyList(nums);
    printLL(head);
    head = reverseList(head);
    printLL(head);
    

    return 0;
}