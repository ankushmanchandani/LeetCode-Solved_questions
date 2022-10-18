class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        
        for(int g=0;g<s.length();g++){
            for(int i=0,j=g; j<dp.size();i++,j++){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if((s[i] == s[j]) && dp[i+1][j-1] == true){
                        dp[i][j] =true;
                    }else{
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};

// g=0 i=0,j=g=0 00 11 22 33 44 55 
    
// g=1 i=0 j=g=1 01 12 23 34 45 56