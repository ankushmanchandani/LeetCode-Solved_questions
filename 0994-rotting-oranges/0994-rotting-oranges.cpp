class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue< pair < pair < int, int>, int >> q;
        int vis[n][m] ;
        
        int cntfresh= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    cntfresh += 1;
                }
            }
        }
        int time = 0;
        int cnt=0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int k=0;k<4;k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    cnt += 1;
                }
            }
            
        }
        if(cntfresh != cnt){
            return -1;
        }
        return time;
    }
};