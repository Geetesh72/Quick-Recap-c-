#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to take tree input recursively
TreeNode* takeInput() {
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    if (value == -1) return nullptr;

    TreeNode* root = new TreeNode(value);

    cout << "Enter left child of " << value << ": ";
    root->left = takeInput();

    cout << "Enter right child of " << value << ": ";
    root->right = takeInput();

    return root;
}

// Iterative Preorder Traversal
vector<int> iPreorder(TreeNode* root) {
    vector<int> preorder;
    if (root == nullptr) return preorder;

    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        preorder.push_back(node->data);

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return preorder;
}

// Iterative Inorder Traversal
vector<int> iInorder(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    TreeNode* node = root;
    stack<TreeNode*> st;
    while (!st.empty() || node != nullptr) {
        if (node != nullptr) {
            st.push(node);
            node = node->left;
        } else {
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

// Iterative Postorder Traversal using Two Stacks
vector<int> iPostOrder(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    stack<TreeNode*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        TreeNode* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left) st1.push(temp->left);
        if (temp->right) st1.push(temp->right);
    }
    while (!st2.empty()) {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

// Iterative Postorder Traversal using One Stack
vector<int> postOrder(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVis = nullptr;

    while (!st.empty() || curr != nullptr) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* peekNode = st.top();
            if (peekNode->right != nullptr && lastVis != peekNode->right) {
                curr = peekNode->right;
            } else {
                ans.push_back(peekNode->data);
                lastVis = st.top();
                st.pop();
            }
        }
    }
    return ans;
}

// Main Function
int main() {
    cout << "Build your binary tree:\n";
    TreeNode* root = takeInput();

    cout << "\nIterative Preorder Traversal: ";
    for (int val : iPreorder(root)) cout << val << " ";

    cout << "\nIterative Inorder Traversal: ";
    for (int val : iInorder(root)) cout << val << " ";

    cout << "\nIterative Postorder Traversal (Two Stacks): ";
    for (int val : iPostOrder(root)) cout << val << " ";

    cout << "\nIterative Postorder Traversal (One Stack): ";
    for (int val : postOrder(root)) cout << val << " ";

    return 0;
}
