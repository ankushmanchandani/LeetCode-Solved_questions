class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        //1. transpose nikalega
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(a[i][j], a[j][i]);
            }
        }
        
        //2. reverse kr dunha saari rows ko
        for(int i=0;i<n;i++){
            reverse(a[i].begin(),a[i].end());
        }
    }
};