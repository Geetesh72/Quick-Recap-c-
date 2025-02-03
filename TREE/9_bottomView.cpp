#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

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

vector<int> bottomView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    map<int, int> omap; // Stores the last node for each vertical line
    queue<pair<TreeNode*, int>> q; // BFS queue, stores nodes and their vertical lines
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;

        // Update the map with the current node's value for this vertical line
        omap[line] = node->data;

        if (node->left) {
            q.push({node->left, line - 1}); // Move left, line decreases
        }
        if (node->right) {
            q.push({node->right, line + 1}); // Move right, line increases
        }
    }

    for (auto it : omap) {
        ans.push_back(it.second); // Collect nodes in bottom view
    }
    return ans;
}

int main() {
    TreeNode *root = buildTree();
    vector<int> result = bottomView(root);
    cout << "Bottom View of the Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
