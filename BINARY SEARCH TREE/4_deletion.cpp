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
/*
logic is quite easy 
idea is if any node broken then it check value if value is greater then it
will get attach to right most node of new subtree cause it take largest element
vice versa is same 

*/
TreeNode*helper(TreeNode*root){
    if(root->left==NULL){
        return root->right;
    }
    else if(root->right==NULL){
        return root->left;
    }
    TreeNode*rightChild = root->right;
    TreeNode*lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
}
TreeNode*findLastRight(TreeNode*root){
    if(root->right==NULL){
        return root;
    }
    return findLastRight(root->right);
}
TreeNode*deleteNode(TreeNode*root, int key){
    if(root==nullptr){
        return NULL;
    }
    if(root->data==key){
        // return helper(root)
    }
    TreeNode*dummy = root;

    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && root->left->data==key){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->right;
            }
        }
        else{
            if(root->right!=NULL && root->right->data==key){
                root->right = helper(root->right);
                break;
            }
            else{
                root =root->right;
            }
        }
    }
    return dummy;
}


int main() {
    cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();
    return 0;
}
