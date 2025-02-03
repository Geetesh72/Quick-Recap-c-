#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to build the Binary Search Tree
TreeNode* buildSearchTree(int minVal = INT_MIN, int maxVal = INT_MAX) {
    int val;
    cout << "Enter the node value (or -1 to stop): ";
    cin >> val;

    if (val == -1 || val <= minVal || val >= maxVal) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << " (value must be in range [" << minVal << ", " << val << "]):\n";
    root->left = buildSearchTree(minVal, val);
    cout << "Enter right child of " << val << " (value must be in range [" << val << ", " << maxVal << "]):\n";
    root->right = buildSearchTree(val, maxVal);

    return root;
}
TreeNode*searchBst(TreeNode*root, int val){
    if(!root){
        return NULL;
    }
    while(root !=NULL && root->data!=val){
        root = (val<root->data)?root->left:root->right;

    }
    return root;

}
int main() {
   cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();

    int searchValue;
    cout << "Enter the value to search in the BST: ";
    cin >> searchValue;

    TreeNode* result = searchBst(root, searchValue);
    if (result) {
        cout << "Value " << searchValue << " found in the BST.\n";
    } else {
        cout << "Value " << searchValue << " not found in the BST.\n";
    }
    return 0;
}
