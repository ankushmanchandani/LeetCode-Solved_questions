class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum=0,count=0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum == k) count++;
            if(mpp.count(sum-k)) count += mpp[sum-k];
            mpp[sum]++;
        }
        return count;
    }
};