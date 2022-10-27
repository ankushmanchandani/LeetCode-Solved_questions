class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
       
        int ans = 0;
        
        vector<vector<int>> dp(n,vector<int>(1001,0));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j]+500;
                int cnt = 1;
                //check if answer already present
                if(dp[j][diff])
                    cnt = dp[j][diff];
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};