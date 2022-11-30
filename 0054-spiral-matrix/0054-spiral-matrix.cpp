class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        int count =0;
        int total = n * m;
        
        int sr = 0;
        int sc = 0;
        int ec = m-1;
        int er = n-1;
        
        while(count < total){
            //printing first row
            for(int i=sc; count < total && i<=ec;i++){
                ans.push_back(mat[sr][i]);
                count++;
            }
            sr++;
            
            //printing last col 
            for(int i=sr; count < total && i<=er ;  i++){
                ans.push_back(mat[i][ec]);
                count++;
            }
            ec--;
            
            //printing last row 
            for(int i=ec; count < total &&  i>=sc ; i--){
                ans.push_back(mat[er][i]);
                count++;
            }
            er--;
            
            //printing first col 
            for(int i=er ; count < total && i>=sr ; i--){
                ans.push_back(mat[i][sc]);
                count++;
            }
            sc++;
            
        }
        return ans;
    }
};