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

TreeNode*insert(TreeNode*root,int val){
    if(!root){
       
        return new TreeNode(val);
    }
    TreeNode*curr =root;
    while(true){
        if(root->data<=val){
            if(curr->right){
                curr=curr->right;
            }
            else{
                curr->right = new TreeNode(val);
                break;
            }
        }
        else {
            if(curr->left){
                curr = curr->left;
            }else{
                curr->left =new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

// 
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        // If the tree is empty, create a new node and return it as the root
        return new TreeNode(val);
    }

    TreeNode* curr = root; // Start from the root
    while (true) {
        if (val < curr->data) {
            // Move to the left subtree
            if (curr->left) {
                curr = curr->left;
            } else {
                // Insert the new node
                curr->left = new TreeNode(val);
                break;
            }
        } else if (val > curr->data) {
            // Move to the right subtree
            if (curr->right) {
                curr = curr->right;
            } else {
                // Insert the new node
                curr->right = new TreeNode(val);
                break;
            }
        } else {
            // Duplicate values are not allowed in a typical BST
            cout << "Duplicate value " << val << " cannot be inserted.\n";
            break;
        }
    }

    return root; // Return the root of the tree
}


int main() {
    cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();
    return 0;
}
