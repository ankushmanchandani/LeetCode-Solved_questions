class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int n,int m , int color,int source){
        if(sr<0 || sr>=n || sc<0 || sc>=m || image[sr][sc] != source){
            return;
        }
        image[sr][sc] = color;
        
        dfs(image,sr-1,sc,n,m,color,source);
        dfs(image,sr+1,sc,n,m,color,source);
        dfs(image,sr,sc+1,n,m,color,source);
        dfs(image,sr,sc-1,n,m,color,source);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        
        int n = image.size();
        int m = image[0].size();
        
        int source = image[sr][sc];
        
        dfs(image,sr,sc,n,m,color,source);
        
        return image;
    }
};