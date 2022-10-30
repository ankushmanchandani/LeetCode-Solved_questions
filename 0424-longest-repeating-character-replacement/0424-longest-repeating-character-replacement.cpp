class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0, j=0 , maxi =0;
        vector<int> count(26);
        int ans=-1;
        while(j<n){
            maxi = max(maxi,++count[s[j] - 'A']);
            if((j-i+1) - maxi > k){
                count[s[i] - 'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};