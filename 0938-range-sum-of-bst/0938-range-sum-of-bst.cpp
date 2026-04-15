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
    void range(TreeNode* root, int low, int high, int &sum){
        if(root==NULL) return ;
        
        if(root->val < low) {
            range(root->right, low, high, sum);
        }
        else if (root->val >high){
            range(root->left, low, high, sum);
        }
        else{
            sum += root->val;
            range(root->left, low, high, sum);
            range(root->right, low, high, sum);        
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        range(root, low, high, sum);
        return sum;
    }
};