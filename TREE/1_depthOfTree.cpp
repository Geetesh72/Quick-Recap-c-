#include <bits/stdc++.h>>
using namespace std;

// Define a node structure
class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to take tree input recursively
TreeNode* takeInput() {
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    // Base case: If the input is -1, return nullptr
    if (value == -1) return nullptr;

    // Create the current node
    TreeNode* root = new TreeNode(value);

    // Recursively build the left subtree
    cout << "Enter left child of " << value << ": ";
    root->left = takeInput();

    // Recursively build the right subtree
    cout << "Enter right child of " << value << ": ";
    root->right = takeInput();

    return root;
}

// about question 
/* we have to tell the height of binary tree 
* 
   Problem: Determine the height of a binary tree.

   The height (or maximum depth) of a binary tree is defined as the number of nodes
   along the longest path from the root node down to the farthest leaf node.

   Approach:
   - Use recursion to calculate the height of the tree.
   - For any given node:
     1. Recursively find the height of the left subtree.
     2. Recursively find the height of the right subtree.
     3. The height of the current node is 1 + max(left subtree height, right subtree height).
   - The base case is when the node is `NULL`, in which case the height is 0.

   Time Complexity (TC):
   - O(n), where n is the number of nodes in the binary tree.
   - Each node is visited exactly once during the recursive traversal.

   Space Complexity (SC):
   - O(h), where h is the height of the binary tree.
   - This accounts for the maximum depth of the recursion stack, which is equal to the tree's height.

*/


int maxDepth(TreeNode*root){
    if(root == NULL){
        return 0;

    }
    int leftTree =maxDepth(root->left);
    int rightTree  = maxDepth (root->right);
    return 1+max(leftTree,rightTree);
}

// Inorder traversal for demonstration
vector<vector<int>>orderLevel(TreeNode*root){
    vector<vector<int>>ans;
    if(root == NULL){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i =0;i<size;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);

    
    }
    return ans;
}


int main() {
    cout << "Build your binary tree:\n";
    TreeNode* root = takeInput();

    
    return 0;
}
