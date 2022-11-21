//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class comparator{
    public:
    bool  operator()(pair<int,int> p1 ,pair<int ,int> p2){
        if(p1.second == p2.second){
            p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
};
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++){
            v[i] = {start[i],end[i]};
        }
        
        sort(v.begin(),v.end(),comparator());
        
        int res=1;
        int last = v[0].second;
        
        for(int i=1;i<n;i++){
            if(v[i].first > last){
                res++;
                last = v[i].second;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends