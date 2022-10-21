class Solution {
public:
    vector<int> partitionLabels(string s) {
        //hashmap store krunga har ek char ka last occurence 
        unordered_map<char,int> map;
        //     char->index
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            map[ch] = i;
        }
        
        //making of result
        int prev=-1, maxi=0;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            maxi = max(maxi,map[ch]);
            if(maxi == i){
                ans.push_back(maxi-prev);
                prev= maxi;
            }
        }
        return ans;
    }
};