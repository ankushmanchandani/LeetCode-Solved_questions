
class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t){
        if(s==NULL || t== NULL){
            return (s==NULL && t==NULL);
        }
        else if(s->val == t->val){
            return isSameTree(s->left,t->left) && isSameTree(s->right,t->right);
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s){
            return false;
        }
        else if(isSameTree(s,t)){
            return true;
        }
        else{
            return isSubtree(s->left,t) || isSubtree(s->right,t);
        }
    }
};