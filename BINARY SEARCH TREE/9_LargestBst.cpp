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

// Helper function to validate if a tree is a BST
bool isBST(TreeNode* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}

// Helper function to count nodes in a tree
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Brute Force Approach
int largestBSTBrute(TreeNode* root) {
    if (!root) return 0;

    // If the current tree is a BST, return the number of nodes
    if (isBST(root, INT_MIN, INT_MAX)) {
        return countNodes(root);
    }

    // Otherwise, recursively find the largest BST in the left and right subtrees
    return max(largestBSTBrute(root->left), largestBSTBrute(root->right));
}

// Optimal Approach using bottom-up traversal
struct TreeInfo {
    int size;       // Size of the largest BST
    int minVal;     // Minimum value in the subtree
    int maxVal;     // Maximum value in the subtree
    bool isBST;     // Whether the subtree is a BST
};

TreeInfo largestBSTOptimalHelper(TreeNode* root) {
    if (!root) return {0, INT_MAX, INT_MIN, true};

    TreeInfo leftInfo = largestBSTOptimalHelper(root->left);
    TreeInfo rightInfo = largestBSTOptimalHelper(root->right);

    if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxVal && root->data < rightInfo.minVal) {
        // Current subtree is a BST
        return {
            leftInfo.size + rightInfo.size + 1,
            min(root->data, leftInfo.minVal),
            max(root->data, rightInfo.maxVal),
            true
        };
    }

    // Current subtree is not a BST
    return {max(leftInfo.size, rightInfo.size), 0, 0, false};
}

int largestBSTOptimal(TreeNode* root) {
    return largestBSTOptimalHelper(root).size;
}

int main() {
    cout << "Build your Binary Tree:\n";
    TreeNode* root = buildSearchTree();

    // Brute force solution
    int largestBSTBruteForce = largestBSTBrute(root);
    cout << "Largest BST size (Brute Force): " << largestBSTBruteForce << endl;

    // Optimal solution
    int largestBSTOptimalSize = largestBSTOptimal(root);
    cout << "Largest BST size (Optimal): " << largestBSTOptimalSize << endl;

    return 0;
}
