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
Node*deleteKthNode(Node*&head,int k){
    Node*temp = head;
    int cnt= 0;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;

    }
    if(cnt==k){
        Node*newHead = head->next;
        return newHead;
    }
    int newCnt = cnt-k;
    cnt = 0;
    temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==newCnt){
            break;
        }
        temp = temp->next;
    }
     Node*delNode = temp->next;
     temp->next = temp->next->next;
    

    
    delete delNode ;
    return head;




}

Node*deleteKNode(Node*&head,int k ){
    Node*fast  = head;
    Node*slow  = head;
    for(int i = 0;i<k;i++){
        fast = fast->next;
    }  
    if(fast == NULL)return head->next;
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node*delNode = slow->next;
    slow->next=slow->next->next;
    free(delNode);
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
    vector<int> nums = {3, 55,6,8,3,5};
    int k;
    cout<<"Enter element that you wanna delete from last: ";
    cin>>k;
    cout<<"Before Delete "<<endl;
    Node *head = convertArrLL(nums);
    printLL(head);
    Node*testHead = head;
    testHead = deleteKthNode(testHead,k);
    cout<<"After Delete :"<<endl;
    printLL(testHead);

    testHead = deleteKNode(head,k);
    cout<<"After Delete :"<<endl;
    printLL(testHead);



    return 0;
}
