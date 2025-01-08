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

bool detectLoopBruteForce(Node*&head){
    unordered_map<Node*,int>umap;
    Node*temp  = head;
    while(temp!=NULL){
        if(umap.find(temp)!=umap.end()){
            return true;
        }
        umap[temp]=1;
        temp = temp->next;
    }
    return false;
} // tc and sc 

// hare and tortoise
bool loopDetection(Node*head){
    Node*slow  = head;
    Node*fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

// lenth of loop 
int lengthOfLoop(Node*&head){
    int timer =1;
    unordered_map<Node*,int>umap;
    Node*temp = head;
    while(temp!=NULL){
        if(umap.find(temp)!=umap.end()){
            int val = umap[temp];
            return timer-val;
        }
        umap[temp]=timer;
        timer++;
        temp =temp->next;


    }
    return 0;
}
int findLength(Node*slow,Node*fast){
    int cnt =1;
    fast =fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt ;
}
int length2(Node*head){
    Node*slow = head;
    Node*fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast =fast->next->next;
        if(slow==fast){
            return findLength(slow,fast);
        }
    }
    
}
Node*deletingMiddleNode(Node*&head){
    Node*slow = head;
    Node*fast = head;
    fast  = fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

    }
    Node*front = slow->next;
    slow->next=slow->next->next;
    delete front;
    return head;


}



 

/// @brief 
/// @return 
int main()
{
    vector<int> nums = {3, 5,5,8,9,6,3,21,4,7};
    Node *head = convertArrLL(nums);
    printLL(head);

    return 0;
}