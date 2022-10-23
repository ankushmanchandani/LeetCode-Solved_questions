class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> map;
        for(int i=0;i<paragraph.length();){
            string word="";
            while(i < paragraph.length() && isalpha(paragraph[i])){
                word.push_back(tolower(paragraph[i++]));
            } 
            while(i < paragraph.length() && !isalpha(paragraph[i])){
                i++;
            }
            map[word]++;
        }
        for(auto x : banned) map[x] = 0;
        
        string res = "";
        int count = 0;
        for(auto x : map){
            if(x.second > count){
                res = x.first;
                count = x.second;
            } 
        }
        return res;
    }
};