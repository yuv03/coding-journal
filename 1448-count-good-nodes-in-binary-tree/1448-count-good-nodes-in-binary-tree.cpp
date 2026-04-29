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
    void gudnode(TreeNode* root, int max, int &count){
        if (root == NULL) return ;

        if (root->val >= max){
            count++;
            max = root->val;
        }

        gudnode(root->left, max, count);
        gudnode(root->right, max, count);
    }


    
    int goodNodes(TreeNode* root) {
        int max = root->val;
        int count = 0;
        gudnode(root, max, count);
        return count;
    }
};