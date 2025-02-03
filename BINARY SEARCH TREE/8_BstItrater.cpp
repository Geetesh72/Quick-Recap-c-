#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to build the Binary Search Tree
TreeNode* buildSearchTree(int minVal = INT_MIN, int maxVal = INT_MAX) {
    int val;
    cout << "Enter the node value (or -1 to stop): ";
    cin >> val;

    if (val == -1 || val <= minVal || val >= maxVal) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << " (value must be in range [" << minVal << ", " << val << "]):\n";
    root->left = buildSearchTree(minVal, val);
    cout << "Enter right child of " << val << " (value must be in range [" << val << ", " << maxVal << "]):\n";
    root->right = buildSearchTree(val, maxVal);

    return root;
}

class BstIterator{
    private:
    stack<TreeNode*>st;
    void pushAll(TreeNode*node){
        for(TreeNode*iter = node; iter!=NULL;st.push(iter),iter = iter->left);
    }
    public:
    BstIterator(TreeNode*root){
        pushAll(root);
    }
    bool hasNext()
    {
        return !st.empty();
    }
    int next(){
        TreeNode*temNode = st.top();
        st.pop();
        pushAll(temNode->right);
        return temNode->data;
    }
};

int main() {
    cout << "Build your Binary Search Tree:\n";
    TreeNode* root = buildSearchTree();
    return 0;
}
