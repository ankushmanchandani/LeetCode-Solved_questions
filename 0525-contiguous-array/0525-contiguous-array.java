class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int ans = 0;
        int sum = 0;
        map.put(0,-1);
        for(int i=0; i<nums.length; i++){
            if(nums[i] == 0){
                sum += -1;
            }
            else if(nums[i] == 1){
                sum += 1;
            }
            if(map.containsKey(sum)){
                int idx = map.get(sum);
                int len = i-idx;
                ans = Math.max(len,ans);
            }
            else{
                map.put(sum,i);
            }
            
        }
        return ans;
    }
}