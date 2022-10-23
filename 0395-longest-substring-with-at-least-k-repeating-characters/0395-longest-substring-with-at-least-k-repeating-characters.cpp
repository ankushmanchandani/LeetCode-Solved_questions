class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n == 0 || k > n) return 0;
        if(k<=1) return n;
        unordered_map<char,int> map;
        for(char c : s){
            map[c]++;
        }
        int left = 0;
        while(left < n && map[s[left]]>=k) left++;
        
        if(left>=n-1) return left;
        int len1 = longestSubstring(s.substr(0,left),k);
        
        while(left<n && map[s[left]]<k) left++;
        
        int len2 = (left<n) ? longestSubstring(s.substr(left),k):0;
        
        return max(len1,len2);
        
        
    }
};