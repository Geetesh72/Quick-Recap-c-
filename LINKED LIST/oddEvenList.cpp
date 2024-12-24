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



Node*oddEvenList(Node*&head){
    Node*temp = head;
    vector<int>nums;

    while(temp!=NULL && temp->next!=nullptr){
        nums.push_back(temp->data);
        temp=temp->next->next;
    }

    if(temp)nums.push_back(temp->data);
    temp = head->next;
     while(temp!=NULL&& temp->next!=nullptr){
        nums.push_back(temp->data);
        temp=temp->next->next;
    }

    if(temp)nums.push_back(temp->data);
    
    Node*finalNode = convertArrLL(nums);
    return finalNode;
}

Node*oddEvenLinkChange(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*odd = head;
    Node*even = head->next;
    Node*evenHead = even;

    while(even!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        // odd->next = even->next
        // odd = odd->next

        even->next = even->next->next;
        // even->next = odd->next;
        // even = even->next



        odd = odd->next;
        even = even->next;

        
    }
    odd->next = evenHead;
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
int main()
{
    vector<int> nums = {1,2,3,5,4,6,7,8};
    Node *head = convertArrLL(nums);
    printLL(head);
    Node*testHead = head;
    head = oddEvenList(head);
    printLL(head);
    Node*head2 =oddEvenLinkChange(testHead);
    printLL(head2);

    return 0;
}