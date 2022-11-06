#define psi pair<int,string>
class mycmp{
    public:
    bool operator()(psi p1, psi p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> freq;
        for(auto word : words){
            freq[word]++;
        }
        
        priority_queue<psi , vector<psi> , mycmp> pq;
        
        for(auto it : freq){
            pq.push({it.second , it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> ans(k);
        int m = k-1;
        while(!pq.empty()){
            ans[m--] = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};