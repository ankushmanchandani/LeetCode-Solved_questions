//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	void solve(int index, string & s, set<string> &set){
	    if(index>=s.length()){
	       set.insert(s);
	       return;
	    }
	    
	    for(int j=index; j<s.length(); j++){
	        swap(s[j],s[index]);
	        solve(index+1,s,set);
	        swap(s[j],s[index]);
	    }
	}
		vector<string>find_permutation(string s)
		{
		    
		    set<string> set;
		    solve(0,s,set);
		    vector<string> ans(set.begin(),set.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends