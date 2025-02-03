#include <bits/stdc++.h>
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

// Helper function to find all paths from root to leaf
void buildPath(TreeNode *root, string paths, vector<string> &ans) {
    if (root == nullptr) {
        return;
    }

    // Add the current node's value to the path
    paths += to_string(root->data);

    // If the current node is a leaf, add the path to the result
    if (!root->left && !root->right) {
        ans.push_back(paths);
    } else {
        paths += "->";  // Add the separator for further nodes
        buildPath(root->left, paths, ans);
        buildPath(root->right, paths, ans);
    }
}

// Main function to get all paths
vector<string> paths(TreeNode *root) {
    vector<string> ans;
    if (root == nullptr) {
        return ans;
    }

    string s;
    buildPath(root, s, ans);
    return ans;
}

int main() {
    TreeNode *root = buildTree();

    vector<string> result = paths(root);

    cout << "Paths from root to leaf are:" << endl;
    for (const string &path : result) {
        cout << path << endl;
    }

    return 0;
}
