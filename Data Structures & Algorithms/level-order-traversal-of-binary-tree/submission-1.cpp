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
        queue<TreeNode*> nodesToProcess;
        vector<vector<int>> ans;

        if(root) nodesToProcess.push(root);

        while(!nodesToProcess.empty()){
            int size = nodesToProcess.size();
            vector<int> currentLevelNodes;
            for(int i=0; i<size; i++){
                TreeNode* currentNode = nodesToProcess.front();
                nodesToProcess.pop();

                if(currentNode->left) nodesToProcess.push(currentNode->left);
                if(currentNode->right) nodesToProcess.push(currentNode->right);
                
                currentLevelNodes.push_back(currentNode->val);
            }

            ans.push_back(currentLevelNodes);
        }
        
        return ans;
    }
};
