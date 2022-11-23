class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        
        
        string ans = "";
        for(int i=0; i<a[0].length(); i++){
            char ch = a[0][i];
            
            bool match = true;
            
            for(int j=1; j<a.size(); j++){
                if(i > a[j].length() || ch != a[j][i] ){
                    match = false;
                    break;
                }
            }
            if(match == false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        
        return ans;
        
    }
};