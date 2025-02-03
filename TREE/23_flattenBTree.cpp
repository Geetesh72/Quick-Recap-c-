#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree
TreeNode* buildTree() {
    int val;
    cout << "Enter the value for the node (-1 for NULL): ";
    cin >> val;
    if (val == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(val);
    cout << "Enter the value of left child of " << val << ": " << endl;
    root->left = buildTree();
    cout << "Enter the value of right child of " << val << ": " << endl;
    root->right = buildTree();
    return root;
}

// Flatten the binary tree to a linked list in preorder
void flatten(TreeNode* root) {
    // Declare `prev` as a static variable to retain its value across recursive calls
    static TreeNode* prev = nullptr;

    if (root == nullptr) {
        return;
    }

    // Recurse on the right subtree first
    flatten(root->right);
    // Recurse on the left subtree
    flatten(root->left);

    // Flatten the current node
    root->right = prev;  // Link the current node to the previously visited node
    root->left = nullptr; // Ensure the left child is null
    prev = root;          // Update `prev` to the current node
}

// Function to print the flattened tree (linked list)
void printFlattenedTree(TreeNode* root) {
    while (root != nullptr) {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

int main() {
    // Build the tree
    TreeNode* root = buildTree();

    // Flatten the tree
    flatten(root);

    // Print the flattened tree
    cout << "Flattened tree (linked list):" << endl;
    printFlattenedTree(root);

    return 0;
}
