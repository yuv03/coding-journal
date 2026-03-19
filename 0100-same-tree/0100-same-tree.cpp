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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* tempa = p;
        TreeNode* tempb = q;
        if(tempa == NULL && tempb == NULL) return true;
        else if(tempa != NULL && tempb == NULL) return false;
        else if(tempa == NULL && tempb != NULL) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool value = p->val==q->val ? true : false;

        if(left && right && value) return true;
        else return false; 
    }
};