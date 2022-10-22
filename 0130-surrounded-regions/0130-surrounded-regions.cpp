class Solution {
public:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    void dfs(int row, int col , vector<vector<char>>& board){
        board[row][col] = '#';
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size()  && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m = board[0].size();
        
        //vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            //first row
            if( board[0][j] == 'O'){
                dfs(0,j,board);
            }
            //last row
            if(board[n-1][j] == 'O'){
                dfs(n-1,j,board);
            }
        }
        
        for(int i=0;i<n;i++){
            //first col
            if(board[i][0] == 'O'){
                dfs(i,0,board);
            }
            //last col
            if(board[i][m-1] == 'O'){
                dfs(i,m-1,board);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};