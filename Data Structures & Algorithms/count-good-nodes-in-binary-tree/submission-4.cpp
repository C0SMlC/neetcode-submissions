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
    void countGoodNodes(TreeNode* root, int& ans, int maxNode){
        if(!root) return;

        countGoodNodes(root->left, ans, max(root->val, maxNode));
        countGoodNodes(root->right, ans, max(root->val, maxNode));

        if(root->val >= maxNode) ans++;
        
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        countGoodNodes(root, ans, root->val);
        return ans;
    }
};
