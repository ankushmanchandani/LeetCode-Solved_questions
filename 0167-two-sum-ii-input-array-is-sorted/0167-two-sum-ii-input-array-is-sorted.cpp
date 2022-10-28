class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int low = 0;
        int high = num.size()-1;
        vector<int> ans;
        while(low<high){
            if(num[low] + num[high] == target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;
            }
            else if(num[low] + num[high] > target){
                high--;
            }
            else{
                low++;
            }
        }
        return ans;
    }
};