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

TreeNode* lowestCommonA(TreeNode* root, TreeNode* nodeOne, TreeNode* nodeTwo) {
    // If root is null or if root is either of the nodes, return root
    if (root == NULL || root == nodeTwo || root == nodeOne) {
        return root;
    }

    // Recur on the left and right subtrees
    TreeNode* leftNode = lowestCommonA(root->left, nodeOne, nodeTwo);
    TreeNode* rightNode = lowestCommonA(root->right, nodeOne, nodeTwo);

    // If one node is found in the left subtree and the other in the right subtree,
    // the current root is the Lowest Common Ancestor
    if (leftNode == NULL) {
        return rightNode;
    } else if (rightNode == NULL) {
        return leftNode;
    } else {
        return root;
    }
}

/*
Explanation:
- If we find one of the nodes that we are looking for, we return the current node.
- If both nodes (nodeOne and nodeTwo) are found in the subtrees of a node, the current node is the lowest common ancestor.
- If only one node is found in the subtree, the other one is not found, so we return NULL for that subtree.
- If both values are found in different subtrees, the current node is returned as the lowest common ancestor.
*/

int main() {
    // Sample usage: Build the tree and call the function
    TreeNode* root = buildTree(); // Build the tree
    TreeNode* nodeOne; // Replace with actual node initialization
    TreeNode* nodeTwo; // Replace with actual node initialization

    // Find the lowest common ancestor of two nodes
    TreeNode* lca = lowestCommonA(root, nodeOne, nodeTwo);
    cout << "Lowest Common Ancestor: " << lca->data << endl;

    return 0;
}
