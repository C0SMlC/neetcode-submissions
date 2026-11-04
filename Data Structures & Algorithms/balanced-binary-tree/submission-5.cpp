/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int checkIfTreeIsBalanced(TreeNode* root){
        if(!root) return 0;

        int leftSubTree = checkIfTreeIsBalanced(root->left);
        if(leftSubTree == -1) return -1;

        int rightSubTree = checkIfTreeIsBalanced(root->right);
        if(rightSubTree == -1) return -1;

        if(abs(leftSubTree - rightSubTree) > 1) return -1;


        return 1 + max(leftSubTree, rightSubTree);
    }

    bool isBalanced(TreeNode* root) {
        return checkIfTreeIsBalanced(root) != -1;
    }
};
