class Solution {
public:
    int f(int ind, int target , vector<int>& a,vector<vector<int>>& dp){
        //base case
        if(ind == 0){
            if(target % a[0] == 0)
                return target / a[ind];
            else
                return 1e9;
        }
        if(dp[ind][target] != -1)
            return dp[ind][target];
        //not take
        int not_take = f(ind-1, target, a ,dp);
        //take
        int take = INT_MAX;
        if(target >= a[ind]){
            take = 1 + f(ind , target - a[ind] , a ,dp);
        }
        return dp[ind][target] =  min(take,not_take);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() , vector<int> (amount+1,-1));
        int ans = f(coins.size()-1,amount, coins, dp);
       return ans>=1e9 ? -1 : ans;
    }
};