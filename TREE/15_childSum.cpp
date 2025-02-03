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

/*
Logic behind the problem:
- We are given a binary tree where the root node should always have a value greater than or equal to the sum of its children's values.
- We can increase the root's value, but we cannot reduce it.
- The approach is:
  1. For each node, calculate the sum of its left and right children's values.
  2. If this sum is greater than or equal to the node's current value, update the node’s value to be the sum.
  3. If the sum is less than the node's value, set the left or right child’s value to the node’s current value to maintain the property of the tree.
  4. Perform the same operation recursively on the left and right children to ensure the entire tree follows this property.

Details of the recursive approach:
- We start by calculating the sum of the left and right children for each node.
- If the sum is greater than or equal to the node's value, we update the node's value.
- If the sum is less, we propagate the node's value to the children (left or right) based on availability.
- The recursion continues to update all nodes from bottom to top, ensuring the child-sum property is met.
*/

void childSum(TreeNode* root) {
    if (root == nullptr) {
        return;  // Base case: If the node is null, we return
    }

    int child = 0;  // Initialize child sum to 0

    // Add the left child's value to the sum, if it exists
    if (root->left) {
        child += root->left->data;
    }

    // Add the right child's value to the sum, if it exists
    if (root->right) {
        child += root->right->data;
    }

    // If the sum of children is greater than or equal to the root's data, update the root's value
    if (child >= root->data) {
        root->data = child;
    } 
    else {
        // If the root's data is greater than the sum, set the value of left or right child to root's data
        if (root->left) root->left->data = root->data;
        else if (root->right) root->right->data = root->data;
    }

    // Recursively process the left and right children
    childSum(root->left);
    childSum(root->right);

    // Recalculate the total value for the current node (sum of left and right children)
    int tot = 0;
    if (root->left) tot += root->left->data;
    if (root->right) tot += root->right->data;

    // If the current node has at least one child, set the root's value to the total of left and right children
    if (root->left || root->right) root->data = tot;
}

int main() {
    TreeNode* root = buildTree();  // Build the binary tree
    childSum(root);  // Apply the child sum property to the tree
    return 0;
}
