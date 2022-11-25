class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int> left(n,-1) , right(n,n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()) left[i] = i-st.top();
            else left[i] = i+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) right[i] = st.top()-i;
            else right[i] = n-i;
            st.push(i);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            long long  prod = (left[i] * right[i])%MOD;
            prod = (prod * arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        return res;
    }
};
