class Solution {
    public int maxSubArray(int[] nums) {
        int cursum = 0;
        int maxi = Integer.MIN_VALUE;
        
        for(int i=0;i<nums.length;i++){
            cursum = cursum + nums[i];
            if(nums[i] > cursum){
                cursum = nums[i];
            }
            if(maxi < cursum){
                maxi = cursum;
            }
        }
        return maxi;
    }
}