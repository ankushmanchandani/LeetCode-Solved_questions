class Solution {
public:
    
    
 
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        if(mat.size() == 0) return ans;
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<bool> >pacific(m, vector<bool>(n, false));
        vector<vector<bool> >atlantic(m, vector<bool>(n, false));
        
        
        //dfs
        for(int i=0;i<m;i++){
            dfs(mat,pacific,i,0) ;
            dfs(mat,atlantic,i,n-1);
        }
            
        for(int i=0;i<n;i++){
            dfs(mat,pacific,0,i);
            dfs(mat,atlantic,m-1,i);
        }
        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
       void dfs(vector<vector<int>>& mat,vector<vector<bool>> &vis,int i,int j){
        if(vis[i][j]){
            return;
        }
        int m = mat.size();
        int n = mat[0].size();    
        
        vis[i][j] = true;

        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j] ) dfs(mat,vis,i - 1,j);
           
        if(i + 1 < m  && mat[i + 1][j] >= mat[i][j] ) dfs(mat,vis,i + 1,j);
           
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j] ) dfs(mat,vis,i,j - 1);
           
        if(j + 1 < n  && mat[i][j + 1] >= mat[i][j] ) dfs(mat,vis,i,j + 1);
        

     }
};