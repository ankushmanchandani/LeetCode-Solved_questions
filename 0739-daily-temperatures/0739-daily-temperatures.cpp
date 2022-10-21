class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
         int n = t.size();
        vector<int> ans(n,0);
       
        int hottest = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(t[i]>=hottest){
                hottest = t[i];
            }
            else{
                int it = i+1;
                while( t[i]>=t[it]){
                    it+=ans[it];
                }
                ans[i]=it-i;
            }
        }
        return ans;
    }
};