#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Tree node structure
struct TreeNode {
    string val;        // Value of the node (string)
    TreeNode* left;    // Pointer to left child
    TreeNode* right;   // Pointer to right child
    TreeNode(string x) : val(x), left(NULL), right(NULL) {} // Constructor
};

int postIndex;  // Global index to track current node in postorder

// Recursive function to build tree from inorder and postorder arrays
TreeNode* buildTree(vector<string>& inorder, vector<string>& postorder, int inStart, int inEnd, unordered_map<string,int>& inMap) {
    if (inStart > inEnd) return NULL; // Base case: no nodes to construct

    // Pick current node from postorder using postIndex
    TreeNode* root = new TreeNode(postorder[postIndex--]);

    // If this node has no children
    if (inStart == inEnd) return root;

    // Find index of root in inorder array using map for fast lookup
    int inIndex = inMap[root->val];

    // IMPORTANT: build right subtree first because postorder is consumed from end
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, inMap);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, inMap);

    return root;
}

// Recursive function to print preorder traversal
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";      // Print root first
    printPreorder(root->left);     // Visit left subtree
    printPreorder(root->right);    // Visit right subtree
}

// Recursive function to delete the tree and free memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);   // Delete left subtree
    deleteTree(root->right);  // Delete right subtree
    delete root;              // Delete current node
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<string> inorder(n), postorder(n);

    cout << "Enter inorder sequence: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    cout << "Enter postorder sequence: ";
    for (int i = 0; i < n; i++) cin >> postorder[i];

    // Build a hashmap for inorder indices for fast lookup
    unordered_map<string,int> inMap;
    for (int i = 0; i < n; i++) inMap[inorder[i]] = i;

    postIndex = n - 1; // Start from the end of postorder
    TreeNode* root = buildTree(inorder, postorder, 0, n - 1, inMap);

    cout << "Preorder traversal of constructed tree: ";
    printPreorder(root);
    cout << endl;

    // Free all allocated memory
    deleteTree(root);

    return 0;
}
