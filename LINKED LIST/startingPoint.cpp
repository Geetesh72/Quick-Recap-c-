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


// starting point using map 
Node*startingNode(Node*&head){
    Node*temp = head;
    unordered_map<Node*,int>umap;
    while(temp!=NULL){
        if(umap.find(temp)!=umap.end()){
            return temp;
        }
        umap[temp]=1;
        temp = temp->next;
        
    }
    return NULL;

}


// optimal one 
/*Why this algo work 

first we detect the loop 
how we sure about how the collide 
if slow at 3 then fast have to on 6  intial /
fast ------------> slow ->d
fast-----------> slow d-1
fast----> slow d-2 
fast->slow d=0



*/
Node*startingNodeTwo(Node*&head){
    Node*slow = head;
    Node*fast  = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast= fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast=fast->next;
    }
    return fast;

}
int main()
{
    vector<int> nums = {3, 5,5,56,8,9};
    Node *head = convertArrLL(nums);
    printLL(head);

    return 0;
}