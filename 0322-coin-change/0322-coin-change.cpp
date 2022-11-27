class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n , vector<int> (amount+1,0));
        for(int T=0;T<=amount; T++){
            if(T % coins[0] == 0){
                  dp[0][T] = T / coins[0];
            }  
            else{
                  dp[0][T] = 1e9;
            }    
        }
        for(int ind=1; ind<n; ind++){
            for(int T = 0 ; T<=amount ; T++){
                int not_take = dp[ind-1][T];
                //take
                int take = INT_MAX;
                if(T >= coins[ind]){
                    take = 1 + dp[ind][T - coins[ind]];
                }
                dp[ind][T] =  min(take,not_take);
            }
            
        }
        long ans = dp[n-1][amount];
        return ans>=1e9 ? -1 : ans;
     
    }
};