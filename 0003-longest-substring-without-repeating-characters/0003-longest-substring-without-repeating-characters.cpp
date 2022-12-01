class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0 || n == 1) return n;
        int i(0) , j(0);
        vector<int> count(256,0);
        count[s[0]]++;
        int len=1;
        while(j!=n-1){
            if(count[s[j+1]] == 0){
                j++;
                count[s[j]]++;
                len = max(len,j-i+1);
            }
            else{
                count[s[i]]--;
                i++;
            }
        }
        return len;
    }
};