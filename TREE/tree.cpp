#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val):data(val),left(NULL),right(NULL){}

};
TreeNode* takeInput() {
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    // Base case: If the input is -1, return nullptr
    if (value == -1) return nullptr;

    // Create the current node
    TreeNode* root = new TreeNode(value);

    // Recursively build the left subtree
    cout << "Enter left child of " << value << ": ";
    root->left = takeInput();

    // Recursively build the right subtree
    cout << "Enter right child of " << value << ": ";
    root->right = takeInput();

    return root;
}
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){ 
    cout << "Build your binary tree:\n";
    TreeNode* root = takeInput();

    cout << "\nInorder traversal of the tree: ";
    inorder(root);
    cout << endl;
return 0;
}