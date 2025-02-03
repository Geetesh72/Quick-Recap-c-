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

/* idea is similar to k-distance node in a binary tree.
   The idea is to "burn" the tree by considering the starting node and propagating 
   the burning upwards (to parent) and downwards (to children) simultaneously. 
   The time complexity depends on the number of nodes in the tree.
*/

// Function to map each node to its parent
TreeNode* parentPointer(TreeNode*root, map<TreeNode*,TreeNode*>&umap, int start){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode* result = nullptr;

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        // If we found the start node, store it as the result
        if(node->data == start) result = node;

        // If the node has a left child, map it to the parent
        if(node->left){
            umap[node->left] = node;
            q.push(node->left);
        }

        // If the node has a right child, map it to the parent
        if(node->right){
            umap[node->right] = node;
            q.push(node->right);
        }
    }
    return result;
}

// Function to calculate the maximum distance from the start node to the farthest node
int findMaxDis(map<TreeNode*,TreeNode*>&omap, TreeNode*target){
    int maxi = 0;
    queue<TreeNode*>q;
    q.push(target);
    map<TreeNode*,int>vis;
    vis[target] = 1;

    // Perform a level-order traversal to calculate the distance
    while(!q.empty()){
        int siz = q.size();
        int fl = 0;

        for(int i = 0; i < siz; i++){
            auto node = q.front();
            q.pop();

            // Check left child
            if(node->left && !vis[node->left]){
                fl = 1;
                q.push(node->left);
                vis[node->left] = 1;
            }

            // Check right child
            if(node->right && !vis[node->right]){
                fl = 1;
                q.push(node->right);
                vis[node->right] = 1;
            }

            // Check parent node
            if(omap[node] && !vis[omap[node]]){
                fl = 1;
                q.push(omap[node]);
                vis[omap[node]] = 1;
            }
        }

        // If a node is visited, increment the time (level)
        if(fl) maxi++;
    }
    return maxi;
}

// Main function to calculate the burn time from the start node
int burnTime(TreeNode*root, int start){
    map<TreeNode*,TreeNode*>omap;

    // Find the target node using the parentPointer function
    TreeNode*target  = parentPointer(root,omap,start);

    // Find the maximum distance (time) to burn the tree
    int maxi = findMaxDis(omap, target);

    return maxi;
}

int main(){
    // Example for testing
    TreeNode*root = buildTree();
    int start;
    cout << "Enter the start node value for burning: ";
    cin >> start;

    int time = burnTime(root, start);
    cout << "The burn time is: " << time << endl;

    return 0;
}
