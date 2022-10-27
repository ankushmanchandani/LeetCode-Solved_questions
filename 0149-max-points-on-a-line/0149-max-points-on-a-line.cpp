class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int max_points = 0;
        int n = p.size();
        if(n<=2)
            return n;
       
        for(int i=0;i<n-1;i++){
            unordered_map<float,int> map;
            for(int j=i+1;j<n;j++){
                if(p[i][0] - p[j][0] != 0){
                    float m  = (float(p[i][1] - p[j][1])/float(p[i][0] - p[j][0]));
                    map[m]++;
                    if(map[m] > max_points)
                        max_points = map[m];
                } 
                else{
                    map[INT_MAX]++;
                    if(map[INT_MAX] > max_points){
                        max_points = map[INT_MAX];
                    }
                }
            }
        }
        return max_points+1;
    }
};