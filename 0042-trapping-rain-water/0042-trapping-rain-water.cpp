class Solution {
public:
    int trap(vector<int>& a) {
        int low=0,  high = a.size()-1;
        int leftmax = 0 , rightmax = 0;
        int res=0;
        while(low<=high){
            if(a[low]<=a[high]){
                if(a[low]>=leftmax) leftmax = a[low];
                else res += (leftmax - a[low]);
                low++;
            }
            else{
                if(a[high]>=rightmax) rightmax = a[high];
                else res += (rightmax - a[high]);
                high--;
            }
        }
        return res;
    }
};