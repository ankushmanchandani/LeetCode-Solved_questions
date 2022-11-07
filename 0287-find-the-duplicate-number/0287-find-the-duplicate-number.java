class Solution {
    public int findDuplicate(int[] nums) {
        int len = nums.length;
        int[] ans = new int[len+1];
        for(int i=0;i<len;i++){
            ans[nums[i]]++;
            if(ans[nums[i]] > 1){
                return nums[i];
            }
        }
        return len;
    }
}