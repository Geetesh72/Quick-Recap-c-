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

vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    map<int, int> omap; // Stores the first node for each vertical line
    queue<pair<TreeNode*, int>> q; // BFS queue, stores nodes and their vertical lines
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;

        // Check if the vertical line already has a node in omap
        if (omap.find(line) == omap.end()) {
            omap[line] = node->data; // Update the map for the first node in this line
        }

        if (node->left) {
            q.push({node->left, line - 1}); // Move left, line decreases
        }
        if (node->right) {
            q.push({node->right, line + 1}); // Move right, line increases
        }
    }

    for (auto it : omap) {
        ans.push_back(it.second); // Collect nodes in top view
    }
    return ans;
}

int main() {
    TreeNode *root = buildTree();
    vector<int> result = topView(root);
    cout << "Top View of the Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

/*answer my question 
what is idea of this 
does this line checking and updating the new value ?if(omap.find(line)==omap.end()){
            omap[line] = node->data;
        }
        If omap.find(line) returns omap.end(), it means no node has been added for this vertical line yet, 
        so omap[line] = node->data stores the current node’s value.
        Once a value is stored for a line, subsequent nodes for the same line are ignored.

time complxit and space ?
BFS Traversal: Each node is visited exactly once, so O(N) where
N is the number of nodes.
Map Operations: Each omap.find() and omap.insert() operation takes 
𝑂
(log𝐾)
O(logK), where 
K is the number of unique vertical lines. Since 
K≤N, this contributes 
O(NlogN).

*/
