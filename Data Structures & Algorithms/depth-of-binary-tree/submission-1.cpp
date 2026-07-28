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
   private:
    void solve(TreeNode* root, int tempHeight, int& depth) {
        if(root == NULL) return ;

        tempHeight++;
        depth = max(depth, tempHeight);

        solve(root->left, tempHeight, depth);
        solve(root->right, tempHeight, depth);

    }

   public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;
        solve(root, 0, depth);
        return depth;
    }
};











