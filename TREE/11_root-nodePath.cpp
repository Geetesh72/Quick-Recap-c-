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

// Helper function to find the path
bool getPath(TreeNode* root, vector<int>& ans, int x) {
    if (!root) return false;  // Base case: If node is NULL, return false

    ans.push_back(root->data);  // Add current node to the path

    if (root->data == x) return true;  // If target node is found, return true

    // Recursively check left and right subtrees
    if (getPath(root->left, ans, x) || getPath(root->right, ans, x)) {
        return true;
    }

    ans.pop_back();  // Remove the current node from the path (backtracking)
    return false;
}

// Function to find the path from root to node b
vector<int> paths(TreeNode* root, int b) {
    vector<int> ans;
    if (root == nullptr) return ans;  // If tree is empty, return empty path
    getPath(root, ans, b);
    return ans;
}

int main() {
    TreeNode *root = buildTree();
    int b;
    cout << "Enter the node value to find path: ";
    cin >> b;

    vector<int> result = paths(root, b);

    if (result.empty()) {
        cout << "Node not found in the tree." << endl;
    } else {
        cout << "Path to node " << b << ": ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
