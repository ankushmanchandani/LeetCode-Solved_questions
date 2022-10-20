
class Solution {
public:
    
    int dfs(TreeNode* root, long long cursum){
        if(root == NULL) return 0;
        int count = 0;
        if(root->val == cursum) count++;
        count +=dfs(root->left,cursum - root->val);
        count +=dfs(root->right,cursum - root->val);
        return count;
    }
    int pathSum(TreeNode* root, int k) {
        if(root == NULL) return 0;
        return   pathSum(root->left,k) + dfs(root,k) + pathSum(root->right,k);
    }
};