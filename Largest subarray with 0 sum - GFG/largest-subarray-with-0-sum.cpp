//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int max_len=0;
        unordered_map<int,int> map;
        map[0]=-1;
        int prefix_sum=0;
        for(int i=0; i<n ;i++){
            prefix_sum += A[i];
            if(map.find(prefix_sum) == map.end()){
                map[prefix_sum] = i;
            }
            int cur_length =  i - map[prefix_sum];
            max_len = max(max_len , cur_length);
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends