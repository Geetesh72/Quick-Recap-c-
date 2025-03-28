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

Node*deleteAll(Node*&head,int val){
    if(head==NULL){
        return head;
    }
    Node*temp  = head;
    while(temp!=NULL){
        if(temp->data == val){
            if(temp==head){
                head = head->next;
            }
            Node*nextNode = temp->next;
            Node*prevNode = temp->back;
            if(nextNode) nextNode ->back = prevNode;
            if(prevNode) prevNode->next = nextNode;
            free (temp);


        }
        else{
            temp = temp->next;
        }
    }
    return head;

}




int main()
{
    vector<int> nums = {48, 2, 41, 2, 4, 8, 9, 3, 2};
    Node *head = doublyList(nums);
    printLL(head);
    

    return 0;
}