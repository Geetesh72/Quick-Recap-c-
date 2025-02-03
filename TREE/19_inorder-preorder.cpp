#include<bits/stdc++.h>
using namespace std;

// Definition of the TreeNode class
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree using preorder and inorder traversals
TreeNode* buildUniqueTree(vector<int> &preO, vector<int> &inO, int preS, int preE, int inS, int inE, map<int, int> &omap) {
    // Base case: If start index exceeds end index, return NULL
    if (preS > preE || inS > inE) {
        return nullptr;
    }

    // Create the root node with the current element in preorder traversal
    TreeNode* node = new TreeNode(preO[preS]);

    // Find the root's index in the inorder traversal using the map
    int inRoot = omap[node->data];

    // Number of nodes in the left subtree
    int nLeft = inRoot - inS;

    // Recursively build the left subtree
    node->left = buildUniqueTree(preO, inO, preS + 1, preS + nLeft, inS, inRoot - 1, omap);

    // Recursively build the right subtree
    node->right = buildUniqueTree(preO, inO, preS + nLeft + 1, preE, inRoot + 1, inE, omap);

    // Return the root of the subtree
    return node;
}

// Wrapper function to build the tree
TreeNode* uniqueTree(vector<int> &preO, vector<int> &inO) {
    // Map to store the indices of elements in the inorder traversal
    map<int, int> omap;
    for (int i = 0; i < inO.size(); i++) {
        omap[inO[i]] = i;
    }

    // Build and return the tree
    return buildUniqueTree(preO, inO, 0, preO.size() - 1, 0, inO.size() - 1, omap);
}

// post & inorder 

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
    // Example input: preorder and inorder traversals
    vector<int> preO = {3, 9, 20, 15, 7};
    vector<int> inO = {9, 3, 15, 20, 7};

    // Build the unique binary tree
    TreeNode* root = uniqueTree(preO, inO);

    // Verify the constructed tree by printing its inorder traversal
    cout << "Inorder traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
