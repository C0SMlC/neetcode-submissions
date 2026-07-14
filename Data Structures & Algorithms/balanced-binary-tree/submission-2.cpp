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
        
        int heightFromLeft = checkIfBalanced(root->left);
        if(heightFromLeft == -1) return -1;

        int heightFromRight = checkIfBalanced(root->right);
        if(heightFromRight == -1) return -1;

        if(abs(heightFromLeft - heightFromRight) > 1) return -1;

        return 1 + max(heightFromLeft, heightFromRight);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        int ans = checkIfBalanced(root);
        return ans != -1;
    }
};
