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
Node*mergeTwoSorted(Node*head1,Node*head2){
    Node*temp1 = head1;
    Node*temp2 =head2;
    Node*dummyNode  = new Node(-1);
    Node*temp = dummyNode;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data < temp2->data){
            temp->next = temp1;
            temp = temp1;
            temp1=temp1->next;

        }else{
            temp->next  = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
        if(temp1){
            temp->next = temp1;
        }else{
            temp->next = temp2;

        }

    }
    return dummyNode->next;
}
int main()
{
    vector<int> nums = {2,4,8,10,12,14,16};
    Node *head = convertArrLL(nums);
    printLL(head);
    vector<int>nums2  = {1,3,3,6,11,14};
    Node*head2 = convertArrLL(nums2);
    printLL(head2);

    return 0;
}