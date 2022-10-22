class Solution {
public:
    void solve(int index,vector<int>& nums,vector<int> output,vector<vector<int>> &ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude
        solve(index+1,nums,output,ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(index+1,nums,output,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(index,nums,output,ans);
        return ans;
    }
};