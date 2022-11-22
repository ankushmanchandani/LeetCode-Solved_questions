class Solution {
    public String longestPalindrome(String s) {
        if(s.length() <= 1){
            return s;
        }
        int max_len = 1;
        int start =0;
        int end=0;
        //odd
        for(int i=0;i<s.length() ;i++){
            int l=i,r=i;
            
            while(l>=0 && r<s.length()){
                if(s.charAt(l) == s.charAt(r)){
                    l--;r++;
                }
                else{
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                start=l+1;
                end = r-1;
                max_len = len;
            }
        }
        //even
        for(int i=0;i<s.length() ;i++){
            int l=i,r=i+1;
            
            while(l>=0 && r<s.length()){
                if(s.charAt(l) == s.charAt(r)){
                    l--;r++;
                }
                else{
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                start=l+1;
                end = r-1;
                max_len = len;
            }
        }
        
        return s.substring(start,end+1);
    }
}