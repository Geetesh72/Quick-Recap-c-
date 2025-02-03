#include<bits/stdc++.h>
using namespace std;

// Definition of TreeNode
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to serialize a binary tree into a string
string serialize(TreeNode* root) {
    if (!root) return ""; // If the root is null, return an empty string

    string s = "";
    queue<TreeNode*> q;
    q.push(root);

    // Perform level-order traversal
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            s.append("#,"); // Append "#" for null nodes
        } else {
            s.append(to_string(node->data) + ','); // Append node's value
            q.push(node->left); // Add left child to the queue
            q.push(node->right); // Add right child to the queue
        }
    }
    return s; // Return the serialized string
}

// Function to deserialize a string into a binary tree
TreeNode* deserial(string data) {
    if (data.size() == 0) {
        return nullptr; // If the data is empty, return null
    }

    stringstream s(data);
    string str;

    // Get the first value from the string and create the root node
    getline(s, str, ',');
    TreeNode* node = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(node);

    // Use a queue to reconstruct the tree level by level
    while (!q.empty()) {
        TreeNode* root = q.front();
        q.pop();

        // Process the left child
        getline(s, str, ',');
        if (str == "#") {
            root->left = nullptr; // If "#" is encountered, set left child to null
        } else {
            TreeNode* leftNode = new TreeNode(stoi(str)); // Create the left child
            root->left = leftNode;
            q.push(leftNode); // Add the left child to the queue
        }

        // Process the right child
        getline(s, str, ',');
        if (str == "#") {
            root->right = nullptr; // If "#" is encountered, set right child to null
        } else {
            TreeNode* rightNode = new TreeNode(stoi(str)); // Create the right child
            root->right = rightNode;
            q.push(rightNode); // Add the right child to the queue
        }
    }
    return node; // Return the root of the reconstructed tree
}

int main() {
    // Example usage of serialize and deserialize functions

    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the binary tree
    string serialized = serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    // Deserialize the string back into a binary tree
    TreeNode* deserializedRoot = deserial(serialized);
    cout << "Deserialization successful. Root node value: " << deserializedRoot->data << endl;

    return 0;
}
