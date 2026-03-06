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

    void getLeaf(TreeNode* root, vector<int>& leafNodes){
        if(root==NULL) return;

        if(root->left ==NULL && root->right==NULL){
            leafNodes.push_back(root->val);
        }
        getLeaf(root->left, leafNodes);
        getLeaf(root->right, leafNodes);
    }


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        getLeaf(root1, v1);
        getLeaf(root2, v2);
        if(v1==v2) return true;
        return false;
    }
};