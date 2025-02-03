#include <bits/stdc++.h>
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

// Vertical Order Traversal
/*
Time complexity (NlogN)
** Explanation of Multiset and Key Ideas:
1. We use a `map<int, map<int, multiset<int>>>` to store the nodes grouped by their:
   - Horizontal distance (x): The first key in the outer map.
   - Level (y): The key in the nested map.
   - Multiset: Ensures sorted order of nodes at the same position (x, y).
2. BFS is used to traverse the tree level by level, which is essential for vertical order traversal.
3. Sorting is naturally handled by the map and multiset, ensuring the correct traversal order.
*/

vector<vector<int>> verticalOrder(TreeNode *root) {
    if (!root) return {}; // Handle empty tree case

    // Map to store nodes by horizontal distance and level
    map<int, map<int, multiset<int>>> nodes;

    // Queue for BFS: stores nodes with their (x, y) coordinates
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}}); // Root starts at x = 0, y = 0

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode *node = it.first;
        int x = it.second.first;  // Horizontal distance
        int y = it.second.second; // Level

        nodes[x][y].insert(node->data);

        // Push left and right children with updated coordinates
        if (node->left) {
            q.push({node->left, {x - 1, y + 1}});
        }
        if (node->right) {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    // Prepare the result from the map
    vector<vector<int>> ans;
    for (auto iter : nodes) { // Iterate through horizontal distances
        vector<int> col;
        for (auto level : iter.second) { // Iterate through levels
            col.insert(col.end(), level.second.begin(), level.second.end());
        }
        ans.push_back(col); // Add column to the result
    }

    return ans;
}

int main() {
    TreeNode *root = buildTree();
    vector<vector<int>> result = verticalOrder(root);

    cout << "Vertical Order Traversal:" << endl;
    for (const auto &col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
