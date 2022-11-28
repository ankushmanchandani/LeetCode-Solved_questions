class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int,int> map;
        //decreasing monotonic stack
        for(int i=nums2.size()-1;i>=0;i--){
            int ele = nums2[i];
            while(!st.empty() and st.top() <= ele ){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            map.insert({ele,res});
            st.push(ele);
        }
        vector<int> ans;
        for(auto x : nums1){
            ans.push_back(map[x]);
        }
        return ans;
    }
};