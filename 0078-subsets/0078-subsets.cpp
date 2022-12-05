class Solution {
public:
    void solve(int index , vector<int>& nums,  vector<vector<int>> &res  ,vector<int>& path){
        if(index == nums.size()){
            res.push_back(path);
            return;
        }
        
        path.push_back(nums[index]);
        solve(index + 1 , nums, res, path);
        path.pop_back();
        
        solve(index + 1 , nums, res, path);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        solve(0, nums, res, path);
        return res;
    }
};