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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> pendingNodesFromCurrentLevel;
        vector<vector<int>> ans = {};

        pendingNodesFromCurrentLevel.push(root);

        while(!pendingNodesFromCurrentLevel.empty()){
            int size = pendingNodesFromCurrentLevel.size();
            vector<int> temp;
            while(size != 0 and !pendingNodesFromCurrentLevel.empty()){
                TreeNode* poppedNode = pendingNodesFromCurrentLevel.front();
                pendingNodesFromCurrentLevel.pop();
                if(poppedNode != nullptr){
                    temp.push_back(poppedNode->val);
                    pendingNodesFromCurrentLevel.push(poppedNode->left);
                    pendingNodesFromCurrentLevel.push(poppedNode->right);
                }
                size--;
            }

            if(!temp.empty()) ans.push_back(temp);
        }

        return ans;
    }
};
