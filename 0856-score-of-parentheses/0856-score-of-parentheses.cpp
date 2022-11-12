class Solution {
public:
    vector<int> map;
    int solve(int lo ,int hi){
        if(lo+1 == hi) return 1;
        int mid = map[lo];
        if(mid == hi) return 2 * solve(lo+1,hi-1);
        return solve(lo,mid) + solve(mid+1,hi);
    }
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int i;
        map.resize(n,0);
        for(i=0;i<n;i++){
            if(s[i] == ')'){
                int t = st.top();
                map[t] = i;
                st.pop();
            }
            else st.push(i);
        }
        return solve(0,n-1);
    }
};