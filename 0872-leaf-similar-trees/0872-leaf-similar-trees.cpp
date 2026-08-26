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
    void leafNodes(TreeNode* root, vector<int> & leafVec){
        if(root== NULL) return ;
        if(root->left== NULL && root->right==NULL){
            leafVec.push_back(root->val);
        }

        leafNodes(root->left, leafVec);
        leafNodes(root->right, leafVec);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        leafNodes(root1, v1);
        leafNodes(root2, v2);

        if(v1==v2)return true;
        return false;
    }
};