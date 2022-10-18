class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size()+1;
        int m = text2.size()+1;
        vector<vector<int>> dp(n,vector<int>(m,0));
        int maxi = 0;
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
                if(dp[i][j] > maxi){
                    maxi = dp[i][j];
                }
            }
        }
        return maxi;
    }
};