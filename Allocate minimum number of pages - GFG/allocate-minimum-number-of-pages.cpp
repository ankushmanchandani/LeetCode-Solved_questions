//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossibleBooks(int barrier ,int arr[], int student, int N){
        int studentcount = 1, pagessum = 0; 
        for(int i=0;i<N;i++){
            if(arr[i] > barrier){
                return false;
            }
            if(pagessum + arr[i] <= barrier){
                pagessum += arr[i];
            }
            else{
                studentcount++;
                pagessum = arr[i];
            }
            
        }
        if(studentcount > student){
                return false;
            }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M){
            return -1;
        }
        int low = A[0];
        int high = 0;
        for(int i=0; i<N;i++){
            low = min(low,A[i]);
            high += A[i];
        }
        int ans =-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(isPossibleBooks(mid,A,M,N)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends