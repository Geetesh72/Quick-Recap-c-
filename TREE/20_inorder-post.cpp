#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree using postorder and inorder traversals
TreeNode* buildTreeFromPostAndIn(vector<int>& postO, vector<int>& inO, int postS, int postE, int inS, int inE, map<int, int>& omap) {
    // Base case: If start index exceeds end index, return NULL
    if (postS > postE || inS > inE) {
        return nullptr;
    }

    // Create the root node with the current element in postorder traversal
    TreeNode* node = new TreeNode(postO[postE]);

    // Find the root's index in the inorder traversal using the map
    int inRoot = omap[node->data];

    // Number of nodes in the left subtree
    int nLeft = inRoot - inS;

    // Recursively build the left subtree
    node->left = buildTreeFromPostAndIn(postO, inO, postS, postS + nLeft - 1, inS, inRoot - 1, omap);

    // Recursively build the right subtree
    node->right = buildTreeFromPostAndIn(postO, inO, postS + nLeft, postE - 1, inRoot + 1, inE, omap);

    // Return the root of the subtree
    return node;
}

// Wrapper function to build the tree
TreeNode* buildTreeFromPostAndIn(vector<int>& postO, vector<int>& inO) {
    // Map to store the indices of elements in the inorder traversal
    map<int, int> omap;
    for (int i = 0; i < inO.size(); i++) {
        omap[inO[i]] = i;
    }

    // Build and return the tree
    return buildTreeFromPostAndIn(postO, inO, 0, postO.size() - 1, 0, inO.size() - 1, omap);
}

// Function to print the tree in inorder for verification
void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    // Example input: postorder and inorder traversals
    vector<int> postO = {9, 15, 7, 20, 3};
    vector<int> inO = {9, 3, 15, 20, 7};

    // Build the unique binary tree
    TreeNode* root = buildTreeFromPostAndIn(postO, inO);

    // Verify the constructed tree by printing its inorder traversal
    cout << "Inorder traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
