class Solution {
public:
  
    int numTrees(int num) {
        vector<int> dp(num+1,0);
        dp[0] = dp[1] = 1;
        
        for(int n=2;n<=num;n++){
            for(int i= 1;i<=n;i++){
                dp[n] += dp[i-1]*dp[n-i];
            }
        }
        
        return dp[num];
    }
};