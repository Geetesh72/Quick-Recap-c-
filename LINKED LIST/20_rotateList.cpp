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
Node*findLength(Node*&head, int k ){
    Node*temp  = head;
    int cnt = 1;
    while(temp!=NULL){
        if(cnt==k)return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;

}
Node*rotateKthposition(Node*head,int k ){
    if(head==NULL || k==0){
        return head;
    }
   
    
    Node*temp = head;
    int cnt = 1;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;

    }
    if(k%cnt==0)return head;
    k  = k%cnt;
    temp->next  = head;
    Node*newLastNode = findLength(head, cnt-k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}
int main()
{
    vector<int> nums = {3, 5,5,8,9,6,3};
    Node *head = convertArrLL(nums);
    printLL(head);
    head = rotateKthposition(head,2);
    printLL(head);

    return 0;
}