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
/*
Logic of this->


*/
Node*reverseLL(Node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*newHead = reverseLL(head->next);
    Node*front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

//k group
Node*getKthNode(Node*&head, int k){
    k-=1;
    Node*temp = head;
    while(temp!=NULL && k>0){
        k--;
        temp = temp->next;

    }
    return temp;
} 
Node*reverseKGroup(Node*&head , int k ){
    Node*temp = head;
    Node*prevLast = NULL;
    while(temp!=NULL){
        Node*kthNode = getKthNode(temp,k);
        if(kthNode==NULL){
            if(prevLast)prevLast->next = temp;
            break;
        }
        Node*nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if(temp==head){
            head = kthNode;

        }else{
            prevLast ->next = kthNode;

        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;

}


int main()
{
    vector<int> nums = {3, 5,8,9,2,4,10,1,2};
    Node *head = convertArrLL(nums);
    printLL(head);
    head = reverseLL(head);
    printLL(head);
    head = reverseKGroup(head,3);
    printLL(head);

    return 0;
}