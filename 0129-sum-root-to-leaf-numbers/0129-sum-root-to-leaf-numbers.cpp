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
public:
    void summ(TreeNode* root, int& ans, string str) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            string s = to_string(root->val);
            str += s;
            if (!str.empty()) {
                int temp = stoi(str);
                ans += temp;
            }
            return;
        }

        string s = to_string(root->val);
        str += s;

        summ(root->left, ans, str);
        summ(root->right, ans, str);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string str = "";
        summ(root, ans, str);
        return ans;
    }
};