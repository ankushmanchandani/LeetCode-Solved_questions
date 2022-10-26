class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> counts(k,0);
        int sum = 0;
        for(auto x : nums){
            sum += (x%k + k)%k;
            counts[sum%k]++;
        }
        int result = counts[0];
        for(auto c : counts){
            result += (c*(c-1))/2;
        }
        return result;
    }
};