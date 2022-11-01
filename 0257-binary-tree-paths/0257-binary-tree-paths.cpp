
class Solution {
public:
    void helper(TreeNode* root,vector<string> &ans,string cur){
        if(!root) return;
        if(root->left || root->right){
            cur += (to_string(root->val) + "->");
        }
            
        else{
            cur += to_string(root->val);
            ans.push_back(cur);
        }
            
        helper(root->left,ans,cur);
        helper(root->right,ans,cur);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string cur = "";
        helper(root,ans,cur);
        return ans;
    }
};