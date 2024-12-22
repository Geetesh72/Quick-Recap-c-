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

Node *deleteNodeHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    } // this will tell the node which have to delete
    free(temp->next);
    temp->next = NULL;
    return head;
}


// delete kth element 
Node*deleteKth(Node*head , int k ){
    if(head == NULL)return NULL;
    if(k==1){
        Node*temp = head;
        head  = head->next;
        free(temp);
        return head;
    }
    int cnt = 1;
    Node*temp = head;
    Node*prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next = temp->next;
           
            free(temp);
            break;

            
        }
        prev = temp; // remember before moving 
        temp=temp->next;
    }
    return head;

}



Node*deleteEle(Node*head , int val ){
    if(head == NULL)return NULL;
    if(head->data==val){
        Node*temp = head;
        head  = head->next;
        free(temp);
        return head;
    }
    
    Node*temp = head;
    Node*prev = NULL;
    while(temp!=NULL){
        
        if(temp->data==val){
            prev->next = temp->next;
           
            free(temp);
            break;

            
        }
        prev = temp; // remember before moving 
        temp=temp->next;
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
    head = deleteNodeHead(head);
    printList(head);
    cout << "New Head of linked List: " << head->data << endl;
    head = deleteTail(head);
    printList(head);
    head = deleteKth(head,5);
    printList(head);
    head = deleteEle(head,9);
    printList(head);
    

    return 0;
}