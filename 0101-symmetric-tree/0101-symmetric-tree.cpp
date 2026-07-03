class Solution {
public:
    
    void solve(TreeNode* l, TreeNode* r, bool& flag){
        
        if(l==NULL && r==NULL ) return ;
        if(l==NULL && r!=NULL){
            flag = false;
            return ;
        }
        else if(l!=NULL && r==NULL){
            flag = false;
            return ;
        }
    
        if(l->val != r->val) flag = false;
        
        solve(l->left, r->right, flag);
        solve(l->right, r->left, flag);        
    }
    
    bool isSymmetric(TreeNode* root) {
        bool flag = true;
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        solve(root->left, root->right, flag);
        return flag;
        
    }
};