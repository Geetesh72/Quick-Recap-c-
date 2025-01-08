/*
if even we will return second node
if odd automatically the middle node is the middl one
*/
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
Node *middleByCnt(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    temp = head;
    int n = (cnt / 2) + 1;
    while (temp != NULL)
    {
        n--;
        if (n == 0)
        {
            return temp;
            break;
        }
        temp = temp->next;
    }
    return temp;
}

// tortoise & haire
/*
when to stop
when fast is at last node
and slow will point to middle node

*/
Node *tortoise_hare(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

} // in odd this correct ans
/* First check fast not equal to null then check fast->next
okay ?

*/

int main()
{
    vector<int> nums = {3, 5, 8, 9, 2, 4};
    Node *head = convertArrLL(nums);
    printLL(head);

    // Node*nodeData = middleByCnt(head);
    // cout<<nodeData->data;
    Node *slow = tortoise_hare(head);
    cout << slow->data;

    return 0;
}