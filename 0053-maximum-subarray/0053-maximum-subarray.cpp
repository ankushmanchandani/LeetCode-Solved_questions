class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0;
        int maxsum = nums[0];
        for(int i=0; i<nums.size(); i++){
            cursum += nums[i];
            if(nums[i] > cursum){
                cursum = nums[i];
            }
            if(maxsum < cursum){
                maxsum = cursum;
            }
        }
        return maxsum;
    }
};