class Solution {
public:
    void solve(int i , vector<int>& nums,vector<vector<int>>& powerset,vector<int>& subset){
        if(i>=nums.size()){
            powerset.push_back(subset);
            return;
        }
        
        //pick it
        subset.push_back(nums[i]);
        solve(i+1,nums,powerset,subset);
        subset.pop_back();
        
        //not pick it
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++; 
        solve(i+1, nums, powerset, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> subset;
        sort(nums.begin() ,nums.end());
        solve(0,nums,powerset,subset);
        return powerset;
    }
};