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
Node*insertAtHead  (Node*head,int val){

    Node*temp = new Node(val);
    temp->next  = head;
    return temp;
}
Node*insertAtTail (Node*head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node*temp  = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}
//Insert at Kth position 
Node*insertAtKth(Node*head , int val,int k ){
    if(head==NULL){
        if(k==1) return new Node(val);
        else return nullptr;
    }

    if(k==1){
        Node*temp = new Node(val);
        temp->next = head;
        return temp;
        
    }

    int cnt = 0;
    Node*temp  = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){ /// one behind is mandatory 
        Node*newNode = new Node(val);   // first connect new node to temp->next 
        newNode->next = temp->next;     // then temp->next = newNode
        temp->next = newNode;
        break;
        }
        temp = temp->next;

    }
    return head;



}



Node*insertBeforeValue(Node*head , int val,int el){
    if(head==NULL){
        return NULL;
    }

    if(head->data==el){
        Node*temp = new Node(val);
        temp->next = head;
        return temp;
        
    }

    
    Node*temp  = head;
    while(temp->next!=NULL){ // important
        
        if(temp->next->data==el){ /// one behind is mandatory 
        Node*newNode = new Node(val);   // first connect new node to temp->next 
        newNode->next = temp->next;     // then temp->next = newNode
        temp->next = newNode;
        break;
        }
        temp = temp->next;

    }
    return head;



}

void printList(Node *head)
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
    vector<int> nums = {12, 5, 3, 6, 4,5,8,9,4,2,1};
    Node *head = convertArrLL(nums);
    printList(head);
    head = insertAtHead(head,17);
    cout<<"Number that added At head of LL : "<<head->data<<endl;
    printList(head);
    head = insertAtTail(head,30);
    printList(head);
    head = insertAtKth(head,88,3);
    printList(head);

    head = insertBeforeValue(head,72,3);
    printList(head);




    return 0;
}