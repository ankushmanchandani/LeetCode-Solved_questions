
class Solution {
    public ListNode reverse(ListNode head , ListNode newHead){
        if(head == null){
            return newHead;
        }
        ListNode nextnode = head.next;
        head.next = newHead;
        return reverse(nextnode , head);
    }
    public ListNode reverseList(ListNode head) {
        // ---recursive-- 
        return reverse(head,null);
        
        
        // ----iterative----
        // if(head == null) return null;
        // ListNode prev = null;
        // ListNode cur = head;
        // ListNode nxt ;
        // while(cur != null ){
        //     nxt = cur.next;
        //     cur.next = prev;
        //     prev = cur;
        //     cur = nxt;
        // }
        // return prev;
    }
}