#include <bits/stdc++.h>
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

/*
Idea: The width of the binary tree is the maximum width of the tree at any level.
A smart way to calculate the width is using level-order traversal (BFS).
For each level, we calculate the distance between the first and last node on that level.

To optimize the space, we redefine the indexing for each node in the queue to use
a unique value. This avoids potential overflow issues with the default integer type
when calculating width at higher levels.
For each level, the index of the left child of node at index `i` is `2*i+1`,
and the index of the right child is `2*i+2`. This reindexing ensures that we can
keep track of the width correctly at each level.

Explanation of why we calculate for the first and last nodes in the queue:
At each level, the first and last nodes correspond to the extreme left and right nodes.
By calculating the difference in their indices (`last - first + 1`), we get the width of the level.
We then compare this with the current maximum width and update the answer.
*/

int width(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int ans = 0;  // Initialize the maximum width to 0
    queue<pair<TreeNode*, int>> q;  // Queue to perform level order traversal
    q.push({root, 0});  // Push the root with index 0

    while (!q.empty()) {
        int size = q.size();  // Number of nodes at the current level
        int mmin = q.front().second;  // To avoid overflow, store the minimum index at this level
        int first, last;  // To track the first and last node at this level

        for (int i = 0; i < size; i++) {
            int currIdx = q.front().second - mmin;  // Reindexing to avoid overflow
            TreeNode* node = q.front().first;  // Get the current node
            q.pop();  // Remove the current node from the queue

            if (i == 0) first = currIdx;  // The first node of the level
            if (i == size - 1) last = currIdx;  // The last node of the level

            // Push the left child to the queue with updated index
            if (node->left) q.push({node->left, currIdx * 2 + 1});
            // Push the right child to the queue with updated index
            if (node->right) q.push({node->right, currIdx * 2 + 2});
        }

        // Update the maximum width by comparing the width of the current level
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main() {
    TreeNode* root = buildTree();  // Build the binary tree
    cout << "Maximum width of the tree: " << width(root) << endl;  // Output the maximum width
    return 0;
}
