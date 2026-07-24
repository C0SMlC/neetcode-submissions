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
    void countGoodNodes(TreeNode* root, int& ans, int maxSoFar){
        if(!root) return;
        if(root->val >= maxSoFar) ans++;

        maxSoFar = max(maxSoFar, root->val);

        countGoodNodes(root->left, ans, maxSoFar);
        countGoodNodes(root->right, ans, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        // if(!root) return 0;
        int ans = 0;
        countGoodNodes(root, ans, root->val);
        return ans;
    }
};
