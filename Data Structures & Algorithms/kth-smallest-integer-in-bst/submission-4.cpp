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
    void findKSmall(TreeNode* root, int k, int& visited, int& s){
        if(!root) return;
        //Go leftmost
        findKSmall(root->left, k, visited, s);
        visited ++;
        if(visited == k){s = root->val; return;}
        findKSmall(root->right, k, visited, s);
    }

    int kthSmallest(TreeNode* root, int k) {
        int s = 0;
        int visited = 0;
        findKSmall(root, k, visited, s);
        return s;
    }
};
