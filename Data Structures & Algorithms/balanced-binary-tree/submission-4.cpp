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
    int checkIfBalanced(TreeNode* root){
        if(!root) return 0;

        int isBalancedOnLeft = checkIfBalanced(root->left);
        if(isBalancedOnLeft == -1) return -1;

        int isBalancedOnRight = checkIfBalanced(root->right);
        if(isBalancedOnRight == -1) return -1;

        if(abs(isBalancedOnRight - isBalancedOnLeft) > 1) return -1;

        return 1 + max(isBalancedOnLeft, isBalancedOnRight);
    }
    bool isBalanced(TreeNode* root) {
        return checkIfBalanced(root) != -1;
    }
};
