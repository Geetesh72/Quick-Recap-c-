#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from user input
TreeNode* buildTree() {
    int val;
    cout << "Enter value for node creation (-1 for no node): ";
    cin >> val;
    if (val == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);
    cout << "Enter the value of the left node of " << val << ": ";
    root->left = buildTree();
    cout << "Enter the value of the right node of " << val << ": ";
    root->right = buildTree();

    return root;
}

/* ABOUT QUESTION
   Problem:
   - Calculate the maximum path sum of a binary tree.

   Key Idea:
   - The maximum path sum is the highest sum of node values along any path in the tree.
   - A path can start and end at any node and does not need to pass through the root.

   Approach:
   - Use a helper function `helperMaxSum` to calculate the maximum sum for each node recursively.
   - For each node, compute the maximum path sum passing through it:
       maxPathSum = leftSubtreeSum + rightSubtreeSum + root->data
   - Update a global variable `maxi` to store the maximum sum encountered.

   Time Complexity:
   - O(n), where n is the number of nodes in the tree.
   - Each node is visited once.

   Space Complexity:
   - O(h), where h is the height of the tree.
   - This accounts for the recursion stack depth.
*/

// Helper function to calculate the maximum path sum
int helperMaxSum(TreeNode* root, int& maxi) {
    if (root == nullptr) {
        return 0;
    }

    // Calculate the maximum sum from left and right subtrees
    int leftSum = max(0, helperMaxSum(root->left, maxi)); // Ignore negative sums
    int rightSum = max(0, helperMaxSum(root->right, maxi));

    // Update the maximum path sum encountered so far
    maxi = max(maxi, leftSum + rightSum + root->data);

    // Return the maximum path sum for the current node
    return root->data + max(leftSum, rightSum);
}

// Function to calculate the maximum path sum of the binary tree
int maxiPathSum(TreeNode* root) {
    int maxi = INT_MIN; // Initialize to a very small value
    helperMaxSum(root, maxi);
    return maxi;
}

bool isSame(TreeNode* p, TreeNode* q) {
    // Base case: if either node is null
    if (p == NULL || q == NULL) {
        return p == q; // Both must be null to be considered the same
    }

    // Check if the current nodes are identical and recursively check their subtrees
    return (p->data == q->data) &&
           isSame(p->left, q->left) &&
           isSame(p->right, q->right);
}


int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        cout << "\nBuilding a binary tree for test case:\n";
        TreeNode* root = buildTree();

        // Compute the maximum path sum of the binary tree
        int result = maxiPathSum(root);
        cout << "The maximum path sum of the binary tree is: " << result << "\n";
    }

    return 0;
}
