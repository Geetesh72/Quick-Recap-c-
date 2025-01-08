/*
array store in heap mem 
linked list is not contigouse in the heap  stack and queue 
always use in browser 

cannot store memory so the use pointer 
what we storing 
data along with pointer 


self define data types 


*/
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
int lengthOfLL(Node*head){
    Node*temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
        


    }
    return len;
}



int main(){
    vector<int>nums ={48,2,5,4};
    // one of the method
    Node* head = convertArrLL(nums);
    Node*temp  = head; // Never ever temper head take temp variable 
    // Traversing the linked list 
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
        
    }cout<<endl;
    cout<<"Length of linked List: "<<lengthOfLL(head);


    return 0;
}