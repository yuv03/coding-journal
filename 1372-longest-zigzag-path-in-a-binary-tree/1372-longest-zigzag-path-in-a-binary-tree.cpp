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

    void path(TreeNode* root, int temp, int &longPath, bool rightt){
        if(root==NULL) return ;
        longPath = max(temp, longPath);

        if(rightt==false){
            path(root->right, temp+1, longPath, true);
            path(root->left, 1, longPath, false);
        }
        else{
            path(root->left, temp+1, longPath, false);
            path(root->right, 1, longPath, true);
        }
    }


    int longestZigZag(TreeNode* root) {
        int longPath = 0;

        path(root->left, 1, longPath, false);
        path(root->right, 1, longPath, true);

        return longPath;
    }
};