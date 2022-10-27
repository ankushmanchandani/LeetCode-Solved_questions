class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int sign = 1;
        int i=0;
       
        while(i<s.size() && s[i] == ' ') i++;
        if(s[i] == '-' || s[i] == '+'){
            sign = s[i] == '-' ?-1 :1;
            i++;
        }
        while(i<s.length()&&s[i]>='0'&&s[i]<='9'){
            int digit = (s[i]-'0')*sign;
            result = result*10 + digit;
            if(sign == 1 && (result > INT_MAX)) return INT_MAX;
            if(sign == -1 && (result < INT_MIN)) return INT_MIN;
            i++;
        }
        return result;
    }
};