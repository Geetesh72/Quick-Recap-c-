#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Build a binary tree
TreeNode *buildTree() {
    int val;
    cout << "Enter the value (-1 for NULL): ";
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode *root = new TreeNode(val);
    cout << "Enter left child of " << val << endl;
    root->left = buildTree();
    cout << "Enter right child of " << val << endl;
    root->right = buildTree();

    return root;
}

/*
    Idea:
    - For a complete binary tree, the number of nodes in the left and right subtrees will follow a pattern:
      If the height of both left and right subtrees are equal, we know that the left subtree is a perfect binary tree,
      and its number of nodes can be calculated as (2^h - 1), where h is the height of the left subtree.
    - If the heights are not equal, we recursively calculate the number of nodes in both the left and right subtrees.
    This approach helps reduce the time complexity to O(log^2 n) in the best case, instead of O(n).

    Functions:
    - leftH: calculates the height of the left subtree.
    - rightH: calculates the height of the right subtree.
    - nodes: computes the total number of nodes in the binary tree.
*/

// Function to calculate the height of the left subtree
int leftH(TreeNode* root) {
    int lh = 0;
    while (root) {
        lh++;
        root = root->left; // Traverse left side of the tree
    }
    return lh;
}

// Function to calculate the height of the right subtree
int rightH(TreeNode* root) {
    int rh = 0;
    while (root) {
        rh++;
        root = root->right; // Traverse right side of the tree
    }
    return rh;
}

// Function to calculate the number of nodes in the binary tree
int nodes(TreeNode* root) {
    if (root == nullptr) {
        return 0; // If the tree is empty, return 0
    }

    // Calculate the height of left and right subtrees
    int leftHeight = leftH(root->left);
    int rightHeight = rightH(root->right);

    // If the left and right subtree heights are equal, it's a perfect binary tree
    if (leftHeight == rightHeight) {
        // If it's a perfect binary tree, the number of nodes can be calculated as (2^h - 1)
        return (1 << leftHeight) - 1; // 2^h - 1
    }
    
    // Otherwise, we need to calculate the number of nodes recursively for both left and right subtrees
    return 1 + nodes(root->left) + nodes(root->right); // 1 (current node) + left subtree + right subtree
}

int main() {
    TreeNode* root = buildTree(); // Build the tree
    cout << "Total number of nodes in the tree: " << nodes(root) << endl; // Calculate and print the number of nodes
    return 0;
}
