class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0, j=0 , maxi =0;
        unordered_map<char,int> map;
        int ans=-1;
        while(j<n){
            maxi = max(maxi,++map[s[j]]);
            if((j-i+1) - maxi > k){
                map[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};