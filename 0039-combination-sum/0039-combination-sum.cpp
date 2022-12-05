class Solution {
public:
    void solve(int i, vector<int>& arr , vector<vector<int>> &res , vector<int> &path , int k){
        if(i == arr.size()){
            if(k == 0){
                res.push_back(path);
            }
            return ;
        }
        
        if(k >= arr[i]){
            path.push_back(arr[i]);
            solve(i , arr, res ,path ,k - arr[i]);
            path.pop_back();
        }
        
        solve(i+1 , arr, res, path , k);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        solve(0, candidates , res , path , target);
        return res;
    }
};