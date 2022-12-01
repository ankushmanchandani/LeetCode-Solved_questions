class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int num1 =-1,num2=-1;
        int cnt1 = 0,cnt2=0;
        int n = nums.length;
        for(int i=0 ;i<n ;i++){
            if(nums[i] == num1){
                cnt1++;
            }
            else if(nums[i] == num2){
                cnt2++;
            }
            else if(cnt1 == 0){
                num1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                num2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 =0;
        cnt2=0;
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<n ;i++){
            if(num1 == nums[i]){
                cnt1++;
            }
            else if(num2 == nums[i]){
                cnt2++;
            }
        }
        
        if(cnt1 > n/3){
            res.add(num1);
        }
        if(cnt2 > n/3){
            res.add(num2);
        }
        return res;
    }
}