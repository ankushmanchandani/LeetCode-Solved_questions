//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void solve(int i, vector<int> arr ,   vector<int> &res , int sum ,int n){
    if(i == n){
        res.push_back(sum);
        return;
    }
    
    solve(i+1 , arr, res , sum + arr[i] , n);
    solve(i+1, arr ,res, sum, n);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
      vector<int> res;
      solve(0,arr,res,0,N);
      sort(res.begin() , res.end());
      return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends