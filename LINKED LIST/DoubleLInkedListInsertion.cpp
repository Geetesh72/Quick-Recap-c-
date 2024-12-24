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

// INSERT AT HEAD
Node *insertAtHead(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head->back = temp;
    return temp;
}
Node *insertAtTail(Node *head, int val)
{
    Node *temp = new Node(val);
    Node *mover = head;
    while (mover->next != NULL){
        mover = mover->next;
    }
    mover->next = temp;
    temp->back=mover;
    return head;

}

Node*insertInbetween (Node*head, int val,int k ){
    Node*mover = head;
    Node*temp = new Node(val);
    int cnt = 0;
    while(mover!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        mover=mover->next;
    }

    if(k==1){
        return insertAtHead(head,val);
    }
    if(mover->next==NULL){
        return insertAtTail(head,val);
    }
    Node*front = mover->next;
    mover->next= temp;
    temp->next = front;
    front->back = temp;
    temp->back = mover;

    return head;


}

// insert before the give node 
void insertBeforeNode(Node*node,int val){
    Node*temp = new Node(val);
    Node*prev = node->back;
    temp->next=node;
    temp->back=prev;
    prev->next = temp;
    node->back=temp;

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
    vector<int> nums = {48, 2, 41, 2, 4, 8, 9, 3, 2};
    Node *head = doublyList(nums);
    printLL(head);
    head = insertAtHead(head, 17);
    printLL(head);
    head = insertAtTail(head,30);
    printLL(head);
    head = insertInbetween(head, 66,5);
    printLL(head);
    insertBeforeNode(head->next->next->next->next,77);
    printLL(head);
    

    return 0;
}