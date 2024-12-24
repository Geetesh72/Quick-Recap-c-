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

/* given sum pair to give the sum given sum */

pair<Node *, Node *> sum(Node *&head, int target)
{
    Node *temp = head;
    pair<Node *, Node *> upi;
    while (temp != NULL)
    {
        Node *inTemp = temp->next;

        while (inTemp != NULL)
        {
            int total = temp->data + inTemp->data;
            if (total == target && total<=target)
            {
                upi.first = temp;
                upi.second = inTemp;
            }
            inTemp = inTemp->next;
        }
        temp = temp->next;
    }
    return upi;
}


// Two pointer jojo 
vector<pair<int,int>> sumTwoPointer(Node*&head,int target){
    Node*left = head;
    Node*right = head;
    vector<pair<int,int>>ans;
    while(right!=NULL){
        right = right->next;
    }
    while(left->data<right->data){
        int total = left->data+right->data;
        if(total<target){
            left = left->next;
        }
        else if(total>target){
            right = right->back;
        }
        else{
            ans.push_back({left->data,right->data});
            left=left->next;
            right = right->back;
            
            
        }
    }
    return ans;


}
int main()
{
    vector<int> nums = {48, 2, 41, 2, 4, 8, 9, 3, 2};
    Node *head = doublyList(nums);
    printLL(head);

    return 0;
}