class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
                //   char->freq
        for(char ch : s){
            map[ch]++;
        }
        //max heap
        priority_queue<pair<int,char>> pq;
        for(auto itr : map){
            pq.push({itr.second,itr.first});
        }
        
        string ans = "";
        pair<int,char> block = {-1,'$'};
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            
            ans += temp.second;
            temp.first--;
            
            if(block.first > 0){
                pq.push(block);
            }
            block = temp;
        }
        if(ans.length() == s.length()){
            return ans;
        }
        return "";
    }
};