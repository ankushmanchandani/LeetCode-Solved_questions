class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> mergeInteval;
        if(interval.size() == 0) return mergeInteval;
        sort(interval.begin() , interval.end());
        vector<int> tempInterval= interval[0];
        
        for(auto it : interval){
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(it[1] , tempInterval[1]);
            }
            else{
                mergeInteval.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergeInteval.push_back(tempInterval);
        return mergeInteval;
    }
};