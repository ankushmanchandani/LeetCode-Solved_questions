class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> res= new ArrayList<>();
        
        if(intervals == null || intervals.length == 0 ){
            return res.toArray(new int[0][]);
        }
        Arrays.sort(intervals, (a , b) -> a[0] - b[0]);
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int[] it : intervals){
            if(it[0]<=end){
                end = Math.max(end,it[1]);
            }
            else{
                res.add(new int[]{start,end});
                start = it[0];
                end = it[1];
            }
        }
        res.add(new int[]{start,end});
        return res.toArray(new int[0][]);
    }
}