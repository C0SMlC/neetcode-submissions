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
    int findMaxSumPath(TreeNode* root, int& ans){
        if(!root) return 0;

        int leftSum = findMaxSumPath(root->left, ans);
        leftSum = max(leftSum, 0);

        int rightSum = findMaxSumPath(root->right, ans);
        rightSum = max(rightSum, 0);

        ans = max(ans, leftSum + rightSum + root->val);

        return max({root->val, leftSum + root->val, rightSum + root->val});
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMaxSumPath(root, maxSum);
        return maxSum;
    }
};
