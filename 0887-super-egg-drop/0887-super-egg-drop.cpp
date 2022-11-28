class Solution {
public:
 
    int superEggDrop(int k, int n) {
        //k -> eggs
        //n -> no of floors
        if(n == 0 || n == 1){
            return n;
        }
        if(k == 1){
            return n;
        }
        vector<vector<int>> dp(k+1, vector(n+1,0));
        for(int i=0; i<=k ;i++){
            dp[i][0] = 0;
            dp[i][1] = 1; 
        }
        for(int i=0; i<=n ;i++){
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        for(int e=2 ; e<k+1 ;e++){
            for(int f=2; f<n+1; f++){
                int ans = 100000;
                int l=1 , h = f , temp = 0 ;
                while(l<=h){
                    int k = (l+h)/2;
                    //egg broke
                    int left = dp[e-1][k-1];
                    //egg not broke
                    int right = dp[e][f-k];

                    temp = 1 + max(left,right);

                    if(left < right){
                        l = k+1;
                    }
                    else{
                        h = k-1;
                    }
                    ans = min(ans,temp);
                }
        
                 dp[e][f] =  ans;
            }
        }
        
        return dp[k][n];
    }
};