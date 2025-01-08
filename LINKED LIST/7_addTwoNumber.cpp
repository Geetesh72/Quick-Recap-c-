#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data; 
    Node*next;
    Node(int data ){
        this->data  = data;
        this->next = nullptr;
    }


};
Node *convertArrLL(vector<int>&nums){
    Node*head = new Node(nums[0]);
    Node*mover = head;
    int n = nums.size();
    for(int i =1;i<n;i++){
        Node*temp = new Node(nums[i]);
        mover->next  = temp;
        mover  = mover->next;
        // mover = temp;  both are the same thing

    }
    return head;

}

Node*addTwoNumber(Node*&temp, Node*&temp2){
    Node*dummyNode = new Node(-1);
    Node*head1 = temp;
    Node*head2 =temp2;
    Node*curr = dummyNode;
    int carry= 0;
    while(head1!=NULL || head2!=NULL){
        int sum =carry ;
        if(head1)sum+=head1->data;
        if(head2) sum+=head2->data;
        Node *newNode = new Node(sum%10);
        carry  = sum/10;
        curr->next = newNode;
        curr = curr->next;
        if(head1) head1= head1->next;
        if(head2) head2 = head2->next;
    }
    if(carry){
        Node*newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;

    
}
// TC O(MAX(N1,N2))
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
    vector<int> nums = {3, 5};
    Node* head = convertArrLL(nums);
   printLL(head);
    vector<int>nums2 = {4 ,5,9,9};
    Node*head2 = convertArrLL(nums2);
    printLL(head2);
    Node*newSum = addTwoNumber(head,head2);
    printLL(newSum);
    

    return 0;
}