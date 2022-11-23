class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> path = new ArrayList<>();
        func(0,s,path,res);
        return res;
    }
    void func(int i,String s, List<String> path, List<List<String>> res){
        if(i>=s.length()){
            res.add(new ArrayList<>(path));
            return;
        }
        
        for(int j=i;j<s.length();j++){
            if(isPalindrome(s,i,j)){
                path.add(s.substring(i,j+1));
                func(j+1,s,path,res);
                path.remove(path.size()-1);
            }
        }
    }
    boolean isPalindrome(String s, int start ,int end){
        while(start<=end){
            if(s.charAt(start++) != s.charAt(end--)){
                return false;
            }
        }
        return true;
    }
}