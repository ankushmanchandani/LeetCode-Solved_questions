class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int l = 0 ,r=0 ;
        int len = INT_MAX;
        int n = nums.size();
        int sum = 0 ;
        while(r < n){
            sum += nums[r++];
            while(sum >= k){
                len = min(len,r-l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};