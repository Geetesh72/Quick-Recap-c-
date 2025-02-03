#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree
TreeNode* buildTree() {
    int val;
    cout << "Enter val of Node: ";
    cin >> val;
    if (val == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(val);
    cout << "Enter left tree of " << val << endl;
    root->left = buildTree();
    cout << "Enter right tree of " << val << endl;
    root->right = buildTree();
    return root;
}

// Zigzag Level Order Traversal
vector<vector<int>> zigZag(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> subans(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // Calculate index based on traversal direction
            int idx = leftToRight ? i : (size - i - 1); // this is logic understood zero vali ko n-1 then 1 vali ko n- etc 
              subans[idx] = node->data;

            // Push child nodes into the queue
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Alternate the traversal direction
        leftToRight = !leftToRight;
        ans.push_back(subans);
    }

    return ans;
}

int main() {
    cout << "Build the binary tree:\n";
    TreeNode* root = buildTree();

    vector<vector<int>> result = zigZag(root);
    cout << "\nZigzag Level Order Traversal:\n";
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

