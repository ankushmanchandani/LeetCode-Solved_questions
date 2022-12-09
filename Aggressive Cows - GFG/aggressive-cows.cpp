//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canPlacedCows(vector<int> &arr, int n, int cows , int dist){
       int co_ord = arr[0] , count=1;
       for(int i=1;i<n;i++){
           if(arr[i] - co_ord >= dist){
               count++;
               co_ord = arr[i];
       }
       if(count == cows){
           return true;
       }
       
    }
    return false;
}
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin() , stalls.end());
        
        int low = 1 , high = stalls[n-1] - stalls[0];
        int res = -1;
        while(low<=high){
            int mid = (low+high)>>1;
            
            if(canPlacedCows(stalls,n,k,mid)){
                res = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends