#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    // Function to perform inorder traversal
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }

    // Function to perform preorder traversal
    void preorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    // Function to perform postorder traversal
    void postorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    BinaryTree bt;

    cout << "Inorder traversal: ";
    bt.inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    bt.preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    bt.postorderTraversal(root);
    cout << endl;

    return 0;
}
