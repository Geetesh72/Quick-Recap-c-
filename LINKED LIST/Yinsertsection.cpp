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

// Logic 
bool YinterSection(Node*&head1,Node*&head2){
    unordered_map<Node*,int>mpp; // mapping is happning not stack 
    Node*temp = head1;
    while(temp!=NULL){
        mpp[temp]=1;
        temp = temp->next;
    }
    Node*temp2 = head2;
    while(temp2!=NULL){
        if(mpp.find(temp2)!=mpp.end()){
            return true;
        }
        temp2 = temp2->next;

    }
    return false;
}

// making same level with shorter one 
/*by counting the length and find the difference 
  making larger one to move to d step ahead so that they start with same level of traversal'

*/
Node*collision(Node*&head1 , Node*&head2 , int d){
    while(d){
        d--;
        head2=head2->next;
    }
    while(head1!=head2){
        head1=head1->next;
        head2 = head2->next;
    }
    return head1;
}

bool YinterSect(Node*&head1 , Node*&head2){
    Node*temp = head1;
    int cnt1 = 0;
    while(temp!=NULL){
        cnt1++;
        temp = temp->next;
    }
    int cnt2 = 0;
    temp =head2;
    while(temp!=NULL){
        cnt2++;
        temp = temp->next;
    }
    if(cnt1<cnt2){
        return collision(head1,head2,cnt2-cnt1);
    }
    if(cnt1>cnt2){
        return collision(head2,head1,cnt1-cnt2);
    }
    return 1;

}
/*
logic is which one is exhoust earlier will go to the next list head -> temp2
        -> after that which exhause later will go the next list head say temp1 

        -> after that we can see that they are on same level that what we wanted 
        -> the first same colliding node is our answer 
        -> edge case what if they not touched list then in this condition 
        -> both the list simultaneously point to null in next pointer 
*/

Node*optimalOne(Node*&head , Node*&head1){
    Node*temp = head;
    Node*temp1 = head1;
    while(temp!=temp1){
        temp = temp->next;
        temp1 = temp1->next;
        if(temp == temp1)return temp1;
        if(temp1==NULL)temp1=head;
        if(temp==NULL)temp = head1;
    }
    return temp;

}


int main()
{
    vector<int> nums = {3, 5,6,7,8};
    Node *head = convertArrLL(nums);
    printLL(head);

    vector<int>nums2 = {1,2,54,3,8};
    Node*head2 = convertArrLL(nums2);
    printLL(head2);

    return 0;
}