class Solution {
public:
    bool solve(int mid,vector<int>& w,int days){
        int sum=0;
        int count_days=1;
        for(int i=0;i<w.size();i++){
            if(sum+w[i]<=mid){
                sum+=w[i];
            }
            else{
                sum=w[i];
                count_days++;
            }
        }
        if(count_days<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int sum=0;
        int max=0;
        for(int i=0;i<w.size();i++){
            if(w[i]>max) max= w[i];
            sum+=w[i];
        }
        int low=max;
        int high=sum;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,w,days)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};