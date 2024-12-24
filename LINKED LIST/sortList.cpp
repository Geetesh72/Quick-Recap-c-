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
Node*sortList(Node*&head){
    Node*temp = head;
    int cntzer0 = 0,cntOne = 0,cntTwo  = 0;
    while(temp!=NULL){
        if(temp->data==0)cntzer0++;
        else if(temp->data==1)cntOne++;
        else cntTwo++;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(cntzer0){
            temp->data = 0;
            cntzer0--;        
        }else if(cntOne){
            temp->data = 1;
            cntOne--;
        }
        else{
            temp->data  = 2;
            cntTwo--;
        }
        temp=temp->next;
    }
    return head; // TC O(2N)
}

Node*sortListLinkChange(Node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*zeroHead = new Node(-1);
    Node*oneHead = new Node(-1);
    Node*twoHead = new Node(-1);
    Node*zero = zeroHead;
    Node*one = oneHead;
    Node*two = twoHead;
    Node*temp =head;
    while(temp!=NULL){
        if(temp->data==0){
            
            zero->next = temp;
            zero = zero->next;
        }else if(temp->data ==1){
            
            one -> next = temp;
            one = one->next;
        }else{
            
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next)?oneHead->next:twoHead->next;
    one->next =twoHead->next;
    two->next =NULL;
    Node*newhead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newhead;
    

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
    vector<int> nums = {0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0};
    Node *head = convertArrLL(nums);
    printLL(head);
    Node*testHead = head;
    head = sortList(head);
    printLL(head);
    testHead = sortListLinkChange(testHead);
    printLL(testHead);


    return 0;
}