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

// Left View Helper
void leftHelper(TreeNode* root, int level, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    if (ans.size() == level) { // Add the first node at each level
        ans.push_back(root->data);
    }
    leftHelper(root->left, level + 1, ans); // Prioritize left subtree
    leftHelper(root->right, level + 1, ans);
}

// Left View Function
vector<int> leftView(TreeNode* root) {
    vector<int> ans;
    leftHelper(root, 0, ans);
    return ans;
}

// Right View Helper
void rightHelper(TreeNode* root, int level, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    if (ans.size() == level) { // Add the first node at each level
        ans.push_back(root->data);
    }
    rightHelper(root->right, level + 1, ans); // Prioritize right subtree
    rightHelper(root->left, level + 1, ans);
}

// Right View Function
vector<int> rightView(TreeNode* root) {
    vector<int> ans;
    rightHelper(root, 0, ans);
    return ans;
}

int main() {
    TreeNode *root = buildTree();

    // Left View
    vector<int> left = leftView(root);
    cout << "Left View of the Tree: ";
    for (int val : left) {
        cout << val << " ";
    }
    cout << endl;

    // Right View
    vector<int> right = rightView(root);
    cout << "Right View of the Tree: ";
    for (int val : right) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
