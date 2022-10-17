class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        int prev2=1,prev=1;
        for(int i=1;i<s.length();i++){
            int x = s[i] - '0';
            int xy = (s[i-1] - '0')*10 + x;
            int count =0;
            if(x>0) count +=prev;
            if(xy >= 10 && xy <= 26) count += prev2;
            
            prev2 = prev;
            prev = count;
        }
        return prev;
    }
};