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

/* Explanation:
- In this problem, we are given a target node and we are asked to find all the nodes at a distance 'k' from the target node.
- We use BFS to find the nodes, but also need to be able to traverse upwards (towards the parent nodes).
- We maintain a map to keep track of each node's parent.
- Using BFS, we start from the target node, visit all its children and parent nodes while keeping track of visited nodes.
- We stop when we have reached a distance 'k' and collect all nodes at that distance.
*/

// Function to mark the parent pointers for each node
void markParentPointer(TreeNode*root, unordered_map<TreeNode*, TreeNode*>&umap) {
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*node = q.front();
        q.pop();
        if(node->left){
            q.push(node->left);
            umap[node->left] = node;
        }
        if(node->right){
            q.push(node->right);
            umap[node->right] = node;
        }
    }
}

// Function to find all nodes at distance k from target node
vector<int> distance(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_Track;
    markParentPointer(root, parent_Track);  // Build the parent mapping

    unordered_map<TreeNode*, bool> vis;  // To track visited nodes
    queue<TreeNode*> q;
    q.push(target);
    vis[target] = true;
    
    int currLev = 0;
    
    while(!q.empty()){
        int size = q.size();
        
        // If current level is equal to k, break out of the loop
        if(currLev == k) break;
        
        currLev++;
        
        for(int i = 0; i < size; i++){
            TreeNode* currNode = q.front(); 
            q.pop();
            
            // Visit the left child
            if(currNode->left && !vis[currNode->left]){
                q.push(currNode->left);
                vis[currNode->left] = true;
            }
            
            // Visit the right child
            if(currNode->right && !vis[currNode->right]){
                q.push(currNode->right);
                vis[currNode->right] = true;
            }
            
            // Visit the parent node
            if(parent_Track[currNode] && !vis[parent_Track[currNode]]){
                q.push(parent_Track[currNode]);
                vis[parent_Track[currNode]] = true;
            }
        }
    }
    
    // Collect all nodes at distance k
    vector<int> ans;
    while(!q.empty()){
        TreeNode* curr = q.front(); 
        q.pop();
        ans.push_back(curr->data);
    }
    
    return ans;
}

int main(){
    TreeNode* root = buildTree(); // Build the tree

    int k, targetValue;
    cout << "Enter the target node value: ";
    cin >> targetValue;
    cout << "Enter the distance k: ";
    cin >> k;

    // Find the target node in the tree
    TreeNode* targetNode = nullptr;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front(); q.pop();
        if(node->data == targetValue){
            targetNode = node;
            break;
        }
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }

    if(targetNode){
        vector<int> result = distance(root, targetNode, k);
        cout << "Nodes at distance " << k << " from target node: ";
        for(int val : result) cout << val << " ";
        cout << endl;
    } else {
        cout << "Target node not found!" << endl;
    }

    return 0;
}
