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
bool validate(TreeNode*root, long long minVal,long long maxVal){
    if(root==NULL)return true;
    if(root->data>=maxVal || root->data<=minVal){
        return false;
    }
    return validate(root->left,minVal,root->data) && validate(root->right,root->data,maxVal);

}
bool isValid(TreeNode*root){
    return validate(root,INT_MIN,INT_MAX);
}

int main() {
    cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();
    return 0;
}
