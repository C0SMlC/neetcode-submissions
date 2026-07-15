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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> unprocessedNode;
        unprocessedNode.push(root);

        vector<int> ans;

        while (!unprocessedNode.empty()) {
            int size = unprocessedNode.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = unprocessedNode.front();
                unprocessedNode.pop();

                //Last node of every level is the rightmost node
                if (i == size - 1) {
                    ans.push_back(node->val);
                }

                if (node->left) unprocessedNode.push(node->left);
                if (node->right) unprocessedNode.push(node->right);
            }
        }

        return ans;
    }
};
