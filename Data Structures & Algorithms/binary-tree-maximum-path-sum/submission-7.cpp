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
    int findMaxPathSum(TreeNode* root, int& maxPathSumNum) {
        if (!root) return 0;

        int MaxFromLeftPath = findMaxPathSum(root->left, maxPathSumNum);
        int MaxFromRightPath = findMaxPathSum(root->right, maxPathSumNum);

        int leftGain = max(0, MaxFromLeftPath);
        int rightGain = max(0, MaxFromRightPath);

        maxPathSumNum = max(maxPathSumNum, root->val + leftGain + rightGain);

        return max({root->val + rightGain, root->val + leftGain});
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxPathSum(root, ans);
        return ans;
    }
};
