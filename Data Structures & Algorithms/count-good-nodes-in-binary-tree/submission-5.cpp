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
    int countGoodNodes(TreeNode* root, int maxEleSeenSoFar){
        if(!root) return 0;
        int goodNodesCount = root->val >= maxEleSeenSoFar ? 1 : 0;
        goodNodesCount += countGoodNodes(root->left, max(root->val, maxEleSeenSoFar));
        goodNodesCount += countGoodNodes(root->right, max(root->val, maxEleSeenSoFar));

        return goodNodesCount;
    }
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);
    }
};
