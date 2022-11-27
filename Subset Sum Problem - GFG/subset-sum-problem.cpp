//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
  
    
    bool isSubsetSum(vector<int>arr, int sum){
        
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        vector<bool> prev(sum+1);
        vector<bool> curr(sum+1);

        prev[0] = true;
        prev[arr[0]] = true;
        
        for(int ind = 1; ind<n ; ind++){
            for(int k=1; k<=sum; k++){
                bool not_take =prev[k];
                bool take = false;
                if(k>=arr[ind]){
                    take = prev[k-arr[ind]];
                }
                 curr[k] =  take | not_take;
            }
            prev = curr; 
            }
        
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends