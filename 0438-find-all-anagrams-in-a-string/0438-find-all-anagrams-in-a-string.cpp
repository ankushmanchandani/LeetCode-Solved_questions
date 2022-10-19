class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        int window = p.size();
        int len = s.size();
        if(window > len)
            return ans;
        
        int i=0,j=0;
        while(j<window){
            phash[p[j] - 'a']+=1;
            shash[s[j] - 'a'] +=1;
            j+=1;
        }
        j-=1;
        while(j<len){
            if(shash == phash){
                ans.push_back(i);
            }
            j+=1;
            if(j!=len){
                shash[s[j] - 'a']+=1;
            }
            shash[s[i] - 'a']-=1;
            i+=1;
        }
        return ans;
    }
};