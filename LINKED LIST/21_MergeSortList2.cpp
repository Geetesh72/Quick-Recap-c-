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
Node*findMiddle(Node*head){
    if(head == NULL || head->next==NULL){
        return head;

    }
    Node*slow = head;
    Node*fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next ;
        fast = fast->next->next;
    }
    return slow;
}
Node*merge2(Node*head,Node*head1){

}

// break down and merge like merge two sorting list 
Node*mergeSortINList(Node*head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    Node*middle = findMiddle(head);
    Node*leftHead = head;
    Node*rightHead = middle->next;
    middle->next = NULL;
    leftHead = mergeSortINList(leftHead);
    rightHead = mergeSortINList(rightHead);
    
    return merge2(leftHead,rightHead);


}

int main()
{
    vector<int> nums = {3, 5,8,5,4,58,6,21,4,5};
    Node *head = convertArrLL(nums);
    printLL(head);

    return 0;
}