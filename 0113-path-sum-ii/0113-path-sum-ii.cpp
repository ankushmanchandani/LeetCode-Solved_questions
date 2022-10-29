
class Solution {
public:
    void getPathSum(TreeNode* root, int targetSum , vector<int> temp, vector<vector<int>> &ans){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL && targetSum == root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        getPathSum(root->left,targetSum - root->val,temp,ans);
        getPathSum(root->right,targetSum - root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        getPathSum(root,targetSum,{},ans);
        return ans;
    }
};