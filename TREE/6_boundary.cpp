#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

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

// Check if a node is a leaf
bool isLeaf(TreeNode *root) {
    return !root->left && !root->right;
}

// Add left boundary (excluding leaf nodes)
void addLeftBoundary(TreeNode *root, vector<int> &ans) {
    TreeNode *node = root->left; // Start from the left child of root
    while (node) {
        if (!isLeaf(node)) ans.push_back(node->data);
        if (node->left)
            node = node->left;
        else
            node = node->right;
    }
}

// Add leaf nodes
void addLeaves(TreeNode *root, vector<int> &ans) {
    if (!root) return;
    if (isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

// Add right boundary (excluding leaf nodes) in reverse order
void addRightBoundary(TreeNode *root, vector<int> &ans) {
    TreeNode *node = root->right; // Start from the right child of root
    vector<int> temp;             // To store nodes temporarily
    while (node) {
        if (!isLeaf(node)) temp.push_back(node->data);
        if (node->right)
            node = node->right;
        else
            node = node->left;
    }
    // Add nodes to the result in reverse order
    for (int i = temp.size() - 1; i >= 0; i--) {
        ans.push_back(temp[i]);
    }
}

// Boundary traversal
vector<int> boundaryTraversal(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;

    // Add root (if it's not a leaf)
    if (!isLeaf(root)) ans.push_back(root->data);

    // Add left boundary
    addLeftBoundary(root, ans);

    // Add leaf nodes
    addLeaves(root, ans);

    // Add right boundary
    addRightBoundary(root, ans);

    return ans;
}

int main() {
    TreeNode *root = buildTree();
    vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
