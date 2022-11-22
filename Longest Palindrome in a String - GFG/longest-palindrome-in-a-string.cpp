//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
         if(s.length() <= 1){
            return s;
        }
        int max_len = 1;
        int start =0;
        int end=0;
        //odd
        for(int i=0;i<s.length() ;i++){
            int l=i,r=i;
            
            while(l>=0 && r<s.length()){
                if(s[l] == s[r]){
                    l--;r++;
                }
                else{
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                start=l+1;
                max_len = len;
            }
        }
        //even
        for(int i=0;i<s.length() ;i++){
            int l=i,r=i+1;
            
            while(l>=0 && r<s.length()){
                if(s[l] == s[r]){
                    l--;r++;
                }
                else{
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                start=l+1;
                max_len = len;
            }
        }
        
        return s.substr(start,max_len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends