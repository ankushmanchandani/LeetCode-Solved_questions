//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] ={0};
        
        for(int i=0; i<str.length() ;i++){
            int num = 0;
            if(str[i]>='a' && str[i]<='z'){
                num = str[i] - 'a';
            }
            else{
                num = str[i] - 'A';
            }
            arr[num]++;
        }
        
        int ans = 0;
        int max = -1;
        for(int i=0;i<26;i++){
            if(arr[i] > max){
                ans = i;
                max = arr[i];
            }
        }
        
        return ans + 'a';
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends