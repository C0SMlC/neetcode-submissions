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
    bool findKthSmallest(TreeNode* root, int k, int& visited, int& ans){
        if(!root) return true;


        // visited += 1;
        //Visit left
        bool leftVisitResult = findKthSmallest(root->left, k, visited, ans);
        if(!leftVisitResult) return false;

        visited += 1;
        if(k == visited){ ans = root->val; return false;}

        bool rightVisitResult = findKthSmallest(root->right, k, visited, ans);
        if(!rightVisitResult) return false;


        return true;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int visited = 0;
        findKthSmallest(root, k, visited, ans);
        return ans;
    }
};
