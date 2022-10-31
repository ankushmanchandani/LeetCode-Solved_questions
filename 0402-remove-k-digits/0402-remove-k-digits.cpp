class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        stack<char> st;
        int n = num.size();
        
        for(char c : num){
            while(!st.empty() && k>0 && st.top() > c){
                st.pop();
                k--;
            }
            if(c!='0' || !st.empty()){
                st.push(c);
            }
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        
        while(!st.empty()){
            num[n-1] = st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
        
        
    }
};