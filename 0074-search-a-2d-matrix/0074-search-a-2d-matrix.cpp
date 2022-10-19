class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        if(mat.size() == 0) return false;
        
        int n = mat.size();
        int m = mat[0].size();
        
        int l = 0, h = n*m - 1;
        
        while(l<=h){
            int mid = l + (h-l)/2 ;
            
            if(mat[mid/m][mid%m] == target){
                return true;
            }
            if(mat[mid/m][mid%m] > target){
               
                h = mid-1;
            }
            else{
                  l = mid+1;
            }
        }
        return false;
    }
};