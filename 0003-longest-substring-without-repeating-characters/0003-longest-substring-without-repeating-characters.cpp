class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int n =s.size();
        int i(0) ,j(0);
        
        int ans = 1;
        vector<int> count(300,0);
        count[s[0]]++;
        while(j!=n-1){
            if(count[s[j+1]] == 0){
                j++;
                count[s[j]]++;
                ans = max(ans,j-i+1);
            }
            else{
                count[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};