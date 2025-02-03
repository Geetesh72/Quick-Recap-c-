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

/**
 * Function to find the ceiling of a given value in a BST.
 * The ceiling is the smallest value in the tree that is greater than or equal to the given value.
 */
int findCeil(TreeNode* root, int val) {
    if (!root) {
        return -1; // If the tree is empty, return -1.
    }

    int ceil = -1;
    while (root != nullptr) {
        if (root->data == val) {
            ceil = root->data;
            return ceil;
        }
        if (val > root->data) {
            root = root->right; // Move to the right subtree if the value is greater.
        } else {
            ceil = root->data; // Update the ceiling.
            root = root->left; // Move to the left subtree to find a smaller ceiling.
        }
    }
    return ceil;
}
/*What is floor 
greater value that is smaller than equal to x 
*/
int findFLoor(TreeNode*root, int val){
    if(!root){
        return 0;
    }
    int floor = -1;
    while(root){
        if(root->data==val){
            floor = root->data;
            return floor;
        }
        if(val>root->data){
            floor = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;

}

int main() {
    cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();

    int searchValue;
    cout << "Enter the value to find the ceiling in the BST: ";
    cin >> searchValue;

    int ceilValue = findCeil(root, searchValue);
    if (ceilValue == -1) {
        cout << "No ceiling found for the value " << searchValue << " in the BST.\n";
    } else {
        cout << "The ceiling of " << searchValue << " is " << ceilValue << ".\n";
    }

     int fValue = findFLoor(root, searchValue);
    if (fValue == -1) {
        cout << "No floor found for the value " << searchValue << " in the BST.\n";
    } else {
        cout << "The floor of " << searchValue << " is " << ceilValue << ".\n";
    }

    return 0;
}
