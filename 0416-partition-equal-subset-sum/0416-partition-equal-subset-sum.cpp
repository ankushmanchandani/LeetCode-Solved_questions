class Solution {
public:
    bool isSubsetSum(vector<int>&arr, int sum){
        int n = arr.size();    
        vector<bool> prev(sum+1), curr(sum+1);
        prev[0] = curr[0] = true;
        if(arr[0]<=sum) prev[arr[0]] = true;
        
        for(int ind = 1; ind<n ; ind++){
            for(int k=1; k<=sum; k++){
                bool not_take = prev[k];
                bool take = false;
                if(k>=arr[ind]){
                    take = prev[k-arr[ind]];
                }
                 curr[k] =  take | not_take;
            }
            prev = curr; 
            }
        
        return prev[sum]; 
    }
    bool canPartition(vector<int>& nums) {
       
        int totsum = 0 ;
        for(int i=0;i<nums.size();i++){
            totsum += nums[i];
        }
        if(totsum % 2 == 1){
            return false;
        }
        
        return isSubsetSum(nums,totsum/2);
    }
};