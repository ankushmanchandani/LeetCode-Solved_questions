class Solution {
public:
    void solve(int i, vector<int>& nums , vector<vector<int>> &res , vector<int> &path){
        if(i == nums.size()){
            res.push_back(path);
            return ;
        }
        
        path.push_back(nums[i]);
        solve(i+1, nums, res , path);
        path.pop_back();
        
        while(i+1<nums.size() && nums[i] == nums[i+1]) i++;
        solve(i+1 , nums, res, path);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin() , nums.end());
        solve(0,nums,res,path);
        return res;
    }
};