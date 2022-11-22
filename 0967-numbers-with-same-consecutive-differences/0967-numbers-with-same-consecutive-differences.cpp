class Solution {
public:
    void dfs(int num ,int n ,int k, vector<int> &result){
        if(n == 0){
            result.push_back(num);
            return;
        }
        
        int lastdigit = num%10;
        if(lastdigit - k >=0 ) dfs(num*10 + lastdigit - k , n-1, k, result);
        if(k>0 && lastdigit + k < 10) dfs(num*10 + lastdigit + k , n-1, k , result);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        if(n == 1) result.push_back(0);
        
        for(int d =1 ;d<=9; ++d){
            dfs(d, n-1 , k, result);
        }
        return result;
    }
};