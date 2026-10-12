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
    void findKSmall(TreeNode* root, int k, stack<int>& s){
        if(!root) return;
        findKSmall(root->left, k, s);

        if(s.size() < k) s.push(root->val);

        findKSmall(root->right, k, s);

    }

    int kthSmallest(TreeNode* root, int k) {
        stack<int> s;

        findKSmall(root, k, s);

        return s.top();
    }
};
