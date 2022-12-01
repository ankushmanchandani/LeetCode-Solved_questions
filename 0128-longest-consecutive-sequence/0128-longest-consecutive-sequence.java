class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        
        for(int num : nums){
            set.add(num);
        }
        int max =0 ;
        for(int n : nums){
            if(set.contains(n+1)){
                continue;
            }
            
            int count = 1;
            while(set.contains(n-count)){
                count++;
            }
            max = Math.max(max,count);
        }
        return max;
    }
}