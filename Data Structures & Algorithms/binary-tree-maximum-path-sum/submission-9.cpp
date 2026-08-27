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
    int findMaxPathSum(TreeNode* root, int& ans){
        if(!root) return 0;

        int leftGain = findMaxPathSum(root->left, ans);
        leftGain = max(leftGain, 0);

        int rightGain = findMaxPathSum(root->right, ans);
        rightGain = max(rightGain, 0);

        ans = max(ans, root->val + leftGain + rightGain);


        return max(root->val + leftGain, root->val + rightGain);

    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxPathSum(root, ans);
        return ans;
    }
};
