
class Solution {
    public void reverse(ListNode start ,ListNode end){
        ListNode prev = null , curr = start , nxt = curr.next;
        while(prev != end){
            curr.next = prev;
            prev = curr;
            curr = nxt;
            if(nxt != null) nxt  = nxt.next;
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || head.next == null || k==1 ){
            return head;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode beforestart = dummy;
        ListNode end = head;
        int i=0;
        while(end != null){
            i++;
            if(i % k == 0){
                //reversal perform krunga
                ListNode start = beforestart.next;
                ListNode endnext  = end.next;
                reverse(start,end);
                beforestart.next = end;
                start.next = endnext;
                end = endnext;
                beforestart = start;
            }
            else{
                end = end.next;
            }
        }
        return dummy.next;
    }
}