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

// Function to find the Lowest Common Ancestor (LCA) in a BST
TreeNode* lca(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    if (root == NULL) {
        return NULL;
    }
    int curr = root->data;

    // If both nodes are greater than current node, move to the right subtree
    if (curr < node1->data && curr < node2->data) {
        return lca(root->right, node1, node2);
    }

    // If both nodes are smaller than current node, move to the left subtree
    if (curr > node1->data && curr > node2->data) {
        return lca(root->left, node1, node2);
    }

    // Current node is the LCA
    return root;
}

// Helper function to find a node with a given value in the BST
TreeNode* findNode(TreeNode* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    if (val < root->data) {
        return findNode(root->left, val);
    } else {
        return findNode(root->right, val);
    }
}

int main() {
    cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();

    cout << "\nEnter the value of the first node: ";
    int val1;
    cin >> val1;

    cout << "Enter the value of the second node: ";
    int val2;
    cin >> val2;

    TreeNode* node1 = findNode(root, val1);
    TreeNode* node2 = findNode(root, val2);

    if (node1 == NULL || node2 == NULL) {
        cout << "One or both nodes are not present in the BST.\n";
    } else {
        TreeNode* ancestor = lca(root, node1, node2);
        if (ancestor != NULL) {
            cout << "The Lowest Common Ancestor of " << val1 << " and " << val2 << " is: " << ancestor->data << endl;
        } else {
            cout << "No Common Ancestor found.\n";
        }
    }

    return 0;
}
