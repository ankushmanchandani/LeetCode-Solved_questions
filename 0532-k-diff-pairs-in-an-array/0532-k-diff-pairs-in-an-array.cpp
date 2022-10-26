class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count=0;
        for(auto x : nums){
            map[x]++;
        }
        if(k>0){
            for(auto x : map){
                if(map.find(x.first+k) != map.end()){
                    count++;
                }
            }
        }
        else{
            for(auto x : map){
                if(x.second > 1){
                    count++;
                }
            }
        }
        return count;
    }
};