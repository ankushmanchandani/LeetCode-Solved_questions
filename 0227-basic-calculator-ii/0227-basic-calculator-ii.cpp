class Solution {
public:
    int calculate(string s) {
        s += '+';
        long long int ans=0 ,cur=0;
        stack<int> st;
        char sign = '+';
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                cur = cur*10 + (s[i] - '0');
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                if(sign == '+'){
                    st.push(cur);
                }
                else if(sign == '-'){
                    st.push((-1)*cur);
                }
                else if(sign == '*'){
                    int num = st.top(); st.pop();
                    st.push(num*cur);
                }
                else if(sign == '/'){
                    int num = st.top(); st.pop();
                    st.push(num/cur);
                }
                cur = 0;
                sign = s[i];
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};