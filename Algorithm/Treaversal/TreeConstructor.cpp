#include <iostream>
#include <vector>
using namespace std;

// Tree node structure
struct TreeNode {
    int val;           // Value of the node
    TreeNode* left;    // Pointer to left child
    TreeNode* right;   // Pointer to right child
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor
};

int preIndex = 0;  // Global index to track current node in preorder

// Recursive function to build tree from preorder and inorder arrays
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL; // Base case: no nodes to construct

    // Pick current node from preorder using preIndex
    TreeNode* root = new TreeNode(preorder[preIndex++]);

    // If this node has no children
    if (inStart == inEnd) return root;

    // Find index of root in inorder array
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inorder[inIndex] == root->val) break;
    }

    // Recursively build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd);

    return root;
}

// Recursive function to print postorder traversal
void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);   // Visit left subtree
    printPostorder(root->right);  // Visit right subtree
    cout << root->val << " ";     // Print root
}


//void deleteTree(TreeNode* root) {
   // if (!root) return;
   // deleteTree(root->left);   // Delete left subtree
    //deleteTree(root->right);  // Delete right subtree
    //delete root;              // Delete current node
//}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder sequence: ";
    for (int i = 0; i < n; i++) cin >> preorder[i];

    cout << "Enter inorder sequence: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    preIndex = 0; // Reset global index before building tree
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1);

    cout << "Postorder traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;

    // Free all allocated memory
   //deleteTree(root);

    return 0;
}
