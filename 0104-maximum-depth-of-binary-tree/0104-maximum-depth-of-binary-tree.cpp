/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

private:
    void solve(TreeNode* root, int &depth, int tempHeight){
        if(root == NULL) return;
        tempHeight++;
        depth = max(depth, tempHeight);

        solve(root->left, depth, tempHeight);
        solve(root->right, depth, tempHeight);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;
        solve(root, depth, 0);
        return depth;
    }
};
















