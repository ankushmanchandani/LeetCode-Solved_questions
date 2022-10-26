#include<algorithm>
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<int> set;
       // 1 1 3 4 5 
        for(int i=0;i<nums.size();i++){
            int cur = nums[i] +k; 
            if(binary_search(nums.begin()+i+1,nums.end(),cur)){
                set.insert(cur);
            }
        }
        return set.size();
    }
};