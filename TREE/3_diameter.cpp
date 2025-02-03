#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from user input
TreeNode* buildTree() {
    int val;
    cout << "Enter node value (-1 for no node): ";
    cin >> val;
    if (val == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << ": ";
    root->left = buildTree();
    cout << "Enter right child of " << val << ": ";
    root->right = buildTree();
    return root;
}

/* ABOUT QUESTION
   Problem:
   - Calculate the diameter of a binary tree.

   Key Idea:
   - The diameter of a binary tree is the length of the longest path between any two nodes.
   - The path may or may not pass through the root node.

   Approach:
   - Use a helper function `height` to calculate the height of the left and right subtrees for each node.
   - Update the maximum diameter (`maxi`) by comparing it with the sum of the heights of the left and right subtrees.
   - The diameter is stored in `maxi`.

   Time Complexity:
   - O(n), where n is the number of nodes in the tree.
   - Each node is visited once.

   Space Complexity:
   - O(h), where h is the height of the tree.
   - This accounts for the maximum depth of the recursion stack.
*/

int height(TreeNode* root, int& maxi) {
    if (root == nullptr) {
        return 0; // Height of an empty subtree is 0
    }
    int leftH = height(root->left, maxi);
    int rightH = height(root->right, maxi);

    // Update the maximum diameter
    maxi = max(maxi, leftH + rightH);

    return 1 + max(leftH, rightH); // Return the height of the current subtree
}

int diameter(TreeNode* root) {
    if (root == nullptr) return 0;
    int maxi = 0; // Initialize maximum diameter
    height(root, maxi);
    return maxi;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        cout << "\nBuilding a binary tree for test case:\n";
        TreeNode* root = buildTree();

        // Compute the diameter of the binary tree
        int result = diameter(root);
        cout << "The diameter of the binary tree is: " << result << "\n";
    }

    return 0;
}
