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
    pair<bool, int> solve(TreeNode* root) {
        if (root == NULL) return {true, 0};

        pair<bool, int> leftNode = solve(root->left);
        pair<bool, int> rightNode = solve(root->right);

        int diff = abs(leftNode.second - rightNode.second);

        int temp = max(leftNode.second, rightNode.second) + 1;
        if (leftNode.first && rightNode.first && (diff <= 1)) {
            return {true, temp};
        }
        else return {false, temp};
    }

   public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};
