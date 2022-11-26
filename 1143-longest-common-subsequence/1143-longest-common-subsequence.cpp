class Solution {
public:
   
    int solveTab(string &a, string &b){
        vector<int>next(b.length()+1,0);
        vector<int>curr(b.length()+1,0);
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;   
            }  
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int> > dp(text1.length(),vector<int>(text2.length(),-1));
        // return f(text1,text2,0,0,dp);
        return solveTab(text1,text2);
    }
};