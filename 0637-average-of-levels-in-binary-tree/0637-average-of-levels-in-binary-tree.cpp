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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;

        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double summ = 0; 
            for(int i=0; i<n; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                summ += frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            ans.push_back(summ/n);
        }
        return ans;
    }
};