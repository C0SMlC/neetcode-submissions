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

    int countGoodNodes(TreeNode* root, int& ans, int maxNodeValSeen){
        if(!root) return 0;

        if(root->val >= maxNodeValSeen) ans++;

        maxNodeValSeen = max(maxNodeValSeen, root->val);

        countGoodNodes(root->left, ans, maxNodeValSeen);
        countGoodNodes(root->right, ans, maxNodeValSeen);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        countGoodNodes(root, ans, root->val);
        return ans;
    }
};
