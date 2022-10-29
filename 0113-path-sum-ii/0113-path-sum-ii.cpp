
class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int k,vector<int> &path, int cursum){
        if(!root)
            return;
        cursum += root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && cursum == k){
            ans.push_back(path);
        }
        solve(root->left,k,path,cursum);
        solve(root->right,k,path,cursum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<int> path; 
        solve(root,k,path,0);
        return ans;
        
    }
};