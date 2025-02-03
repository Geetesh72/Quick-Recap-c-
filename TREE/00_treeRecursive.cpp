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

// Inorder traversal for demonstration
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(TreeNode*root){
    if(!root)return;
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(TreeNode*root){
    if(!root)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}

vector<int> levelOrder(TreeNode*root){
    if(root==nullptr){
        return {-1};
    }
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        ans.push_back(node->data);
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }

    }
    return ans;
}
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

    cout << "\nInorder traversal of the tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
