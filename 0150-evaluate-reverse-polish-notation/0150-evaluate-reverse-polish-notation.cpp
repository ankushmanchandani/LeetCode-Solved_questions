class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        
        for(string x : tokens){
            if(x == "+"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(a+b);
            }
            else if(x == "*"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(a*b);
            }
            else if(x == "-"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(b-a);
            }
            else if(x == "/"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(b/a);
            }
            else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};