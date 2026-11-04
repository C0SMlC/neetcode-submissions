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

        vector<vector<int>> ans;

        queue<TreeNode* > nodesToProcess;
        nodesToProcess.push(root);

        while(!nodesToProcess.empty()){
            int size = nodesToProcess.size();

            vector<int> nodes;
            int i = 0;
            while(i < size){
                TreeNode* idk = nodesToProcess.front();
                nodesToProcess.pop();
                nodes.push_back(idk->val);

                if(idk->left) nodesToProcess.push(idk->left);
                if(idk->right) nodesToProcess.push(idk->right);

                i++;
            }

            ans.push_back(nodes);
        }

        return ans;
    }
};
