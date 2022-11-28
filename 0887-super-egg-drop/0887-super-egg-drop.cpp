class Solution {
public:
    int solve(int e, int f , vector<vector<int>> &dp){
        //base case
        if(f == 0 || f == 1 || e == 1){
            return f;
        }
        if(dp[e][f] != -1){
            return dp[e][f];
        }
        int ans = INT_MAX;
        int l=1 , h = f , temp = 0 ;
        while(l<=h){
            int k = (l+h)/2;
            //egg broke
            int left = solve(e-1, k-1,dp);
            //egg not broke
            int right = solve(e, f-k ,dp);
            
            temp = 1 + max(left,right);
            
            if(left < right){
                l = k+1;
            }
            else{
                h = k-1;
            }
            ans = min(ans,temp);
        }
        
        return dp[e][f] =  ans;
       
    }
    int superEggDrop(int k, int n) {
        //k -> eggs
        //n -> no of floors
        vector<vector<int>> dp(k+1, vector(n+1,-1));
        return solve(k,n,dp);
    }
};