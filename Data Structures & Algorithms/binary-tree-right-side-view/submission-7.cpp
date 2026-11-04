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
        if(!root) return {};

        queue<TreeNode* > pendingNodesToCheck;
        pendingNodesToCheck.push(root);

        vector<int> ans;

        while(!pendingNodesToCheck.empty()){
            int size = pendingNodesToCheck.size();

            int i = 0;

            while(i < size){
                TreeNode* currentNode = pendingNodesToCheck.front();
                pendingNodesToCheck.pop();
                if(i == size-1) ans.push_back(currentNode->val);

                if(currentNode->left) pendingNodesToCheck.push(currentNode->left);
                if(currentNode->right) pendingNodesToCheck.push(currentNode->right);

                i++;
            }
        }

        return ans;
    }
};
