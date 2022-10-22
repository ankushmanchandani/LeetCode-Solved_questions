class Solution {
public:
    void solve(int index, int k, vector<vector<int>> &ans,vector<int> output,int n ){
        //base case
        if(output.size() == k){
            ans.push_back(output);
            return;
        }
        
        for(int i=index;i<n+1;i++){
            output.push_back(i);
            solve(i+1,k,ans,output,n);
            //backtrack
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        int index =1;
        solve(index,k,ans,output,n);
        return ans;
    }
};