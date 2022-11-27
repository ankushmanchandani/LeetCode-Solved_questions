class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int T=0;T<=amount; T++){
            if(T % coins[0] == 0){
                  prev[T] = T / coins[0];
            }  
            else{
                  prev[T] = 1e9;
            }    
        }
        for(int ind=1; ind<n; ind++){
            for(int T = 0 ; T<=amount ; T++){
                int not_take = prev[T];
                //take
                int take = INT_MAX;
                if(T >= coins[ind]){
                    take = 1 + curr[T - coins[ind]];
                }
                curr[T] =  min(take,not_take);
            }
            prev =curr;
        }
        long ans = prev[amount];
        return ans>=1e9 ? -1 : ans;
     
    }
};