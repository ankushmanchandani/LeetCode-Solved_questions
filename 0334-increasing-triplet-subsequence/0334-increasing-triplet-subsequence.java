class Solution {
    public boolean increasingTriplet(int[] nums) {
        int small = Integer.MAX_VALUE;
        int big = Integer.MAX_VALUE;
        for(int a : nums)
            if(a<=small) small = a;
            else if(a <= big) big =a;
            else return true;
        return false;
    }
}