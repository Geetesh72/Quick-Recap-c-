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

Node *ArraytoDoublyLL(Node *head, vector<int> &nums)
{
    int n = nums.size();
    Node *prev = head;
    for (int i = 1; i < n; i++){
        Node*temp = new Node(nums[i]);
        prev->next = temp;
        temp->back = prev;
        prev  = prev->next;
        // prev  = temp;
    

    }
    return head;
}
Node*deleteHead(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*temp = head->next;
    head->next = NULL;
    temp->back=NULL;
    return temp;

}


// delete tail 
Node*deleteTail(Node*head ){
    if(head == NULL || head->next==NULL)
    {
        return NULL;
    }
    Node*temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*prev = temp->back;
    prev->next = NULL;
    temp->back=NULL;    

    return head;
}
Node*deleteKth(Node*head, int k ){
    if(head == NULL){
        return NULL;
    }
    Node*temp = head ;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){

            break;
        }
        temp = temp->next;
    }
    Node*prev = temp->back;
    Node*front = temp->next;

    if(prev==NULL && front==NULL){
        delete temp;
        return NULL;
    }
    else if (prev==NULL){
        return deleteHead(head);
        
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    else {
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = NULL;
        delete temp;
    }
    return head;
}





void printLL(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }cout<<endl;
}



int main()
{
    vector<int> nums = {7, 5, 1, 4, 2, 5, 8, 9, 3};
    Node *head = new Node(nums[0]);
    head = ArraytoDoublyLL(head,nums);
    printLL(head);
    head = deleteHead(head);
    printLL(head);
    head = deleteTail(head);
    printLL(head);
    head = deleteKth(head,3);
    printLL(head);

    return 0;
}