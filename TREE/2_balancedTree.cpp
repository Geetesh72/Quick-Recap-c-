#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

/* ABOUT QUESTION
   Problem:
   - Determine if a binary tree is height-balanced.

   Key Idea:
   - A binary tree is considered balanced if, for every node:
       | Height(left subtree) - Height(right subtree) | <= 1
   - This means the height difference between the left and right subtrees of any node must not exceed 1.

   Approach:
   - Use a helper function `checkBalanced`:
       1. Calculate the height of the left and right subtrees recursively.
       2. If any subtree is unbalanced (returns -1), propagate -1 upwards.
       3. If the height difference exceeds 1, mark the tree as unbalanced by returning -1.
       4. Otherwise, return the height of the subtree.
   - Use `balanced` as a wrapper function:
       - Call `checkBalanced` and determine if the tree is balanced based on the result.

   Time Complexity:
   - O(n), where n is the number of nodes in the tree.
   - Each node is visited once.

   Space Complexity:
   - O(h), where h is the height of the tree.
   - This accounts for the maximum depth of the recursion stack.
*/

int checkBalanced(TreeNode*& root) {
    if (root == NULL) {
        return 0; // Height of an empty subtree is 0
    }

    int leftH = checkBalanced(root->left);
    int rightH = checkBalanced(root->right);

    // If any subtree is unbalanced, propagate -1
    if (leftH == -1 || rightH == -1 || abs(leftH - rightH) > 1) {
        return -1; // Mark as unbalanced
    }

    return max(leftH, rightH) + 1; // Return the height of the current subtree
}

bool balanced(TreeNode* root) {
    return checkBalanced(root) != -1;
}

// Function to build a binary tree from user input
TreeNode* buildTree() {
    int val;
    cout << "Enter node value (-1 for no node): ";
    cin >> val;

    if (val == -1) return NULL;

    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << ": ";
    root->left = buildTree();
    cout << "Enter right child of " << val << ": ";
    root->right = buildTree();

    return root;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        cout << "\nBuilding a binary tree for test case:\n";
        TreeNode* root = buildTree();

        if (balanced(root)) {
            cout << "The binary tree is balanced.\n";
        } else {
            cout << "The binary tree is not balanced.\n";
        }
    }

    return 0;
}
