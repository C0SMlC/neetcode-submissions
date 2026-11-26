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

        int sumFromLeft = max(0, findMaxPathSum(root->left, ans));
        int sumFromRight = max(0, findMaxPathSum(root->right, ans));

        ans = max({ans, root->val + sumFromLeft + sumFromRight});

        return max(sumFromLeft + root->val, sumFromRight + root->val);     
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxPathSum(root, ans);

        return ans;
    }
};
