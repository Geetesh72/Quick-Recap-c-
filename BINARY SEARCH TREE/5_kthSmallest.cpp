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

/*
Inorder traversal of a Binary Search Tree (BST) gives sorted elements.
*/

// Helper function to find the k-th smallest element using inorder traversal
int inorder(TreeNode* root, int& cnt, int k) {
    if (!root) {
        return -1; // Base case
    }

    // Traverse the left subtree
    int left = inorder(root->left, cnt, k);
    if (left != -1) return left; // If k-th element is found in the left subtree

    // Process the current node
    cnt++;
    if (cnt == k) {
        return root->data; // k-th smallest element found
    }

    // Traverse the right subtree
    return inorder(root->right, cnt, k);
}

// Helper function to perform inorder traversal and store elements in an array
void inorderArray(TreeNode* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }
    inorderArray(root->left, ans);
    ans.push_back(root->data);
    inorderArray(root->right, ans);
}

// Function to find the k-th smallest element using recursive inorder traversal
int kth(TreeNode* root, int k) {
    int cnt = 0; // Counter to track the number of elements visited
    int result = inorder(root, cnt, k);
    if (result == -1) {
        cout << "k is out of range.\n";
    }
    return result;
}

// Function to find the k-th smallest element using an array-based approach
int kth2(TreeNode* root, int k) {
    vector<int> ans;
    inorderArray(root, ans);
    if (k <= 0 || k > ans.size()) {
        cout << "k is out of range.\n";
        return -1;
    }
    return ans[k - 1]; // Adjusting for 0-based indexing
}

int main() {
    cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();

    int k;
    cout << "Enter the value of k to find the k-th smallest element: ";
    cin >> k;

    int result = kth(root, k);
    if (result != -1) {
        cout << "The " << k << "-th smallest element (using recursive approach) is: " << result << endl;
    }

    result = kth2(root, k);
    if (result != -1) {
        cout << "The " << k << "-th smallest element (using array approach) is: " << result << endl;
    }

    return 0;
}
