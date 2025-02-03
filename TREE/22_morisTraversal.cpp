#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

/*
Morris Traversal for Inorder Traversal:
1. It uses constant space (O(1)) and avoids the use of recursion or a stack.
2. The key idea is to create a temporary threaded binary tree during traversal.
3. Steps:
   - If the current node has no left child, process it and move to the right child.
   - If the current node has a left child, find its inorder predecessor:
       - If the predecessor's right is NULL, make the current node its right child (thread it) and move to the left child.
       - If the predecessor's right is the current node, remove the thread, process the current node, and move to the right child.
4. This ensures the tree structure is restored after traversal.

Time Complexity: O(n) for n nodes.
Space Complexity: O(1) (constant space).
*/

vector<int> morisTraversal(TreeNode* root) {
    vector<int> moris; // To store the inorder traversal
    if (root == NULL) {
        return moris;
    }

    TreeNode* curr = root;

    while (curr != NULL) {
        // Case 1: If there is no left child
        if (!curr->left) {
            moris.push_back(curr->data); // Process the current node
            curr = curr->right; // Move to the right child
        }
        // Case 2: If there is a left child
        else {
            TreeNode* prev = curr->left;

            // Find the inorder predecessor (rightmost node in the left subtree)
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            // Case 2a: If the right pointer of the predecessor is NULL
            if (prev->right == NULL) {
                prev->right = curr; // Create a temporary thread to the current node
                curr = curr->left; // Move to the left child
            }
            // Case 2b: If the right pointer of the predecessor points to the current node
            else {
                prev->right = NULL; // Remove the temporary thread
                moris.push_back(curr->data); // Process the current node
                curr = curr->right; // Move to the right child
            }
        }
    }
    return moris; // Return the inorder traversal
}

int main() {
    // Example to test the Morris Traversal
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> inorder = morisTraversal(root);

    cout << "Morris Traversal (Inorder): ";
    for (int val : inorder) {
        cout << val << " ";
    }

    return 0;
}
