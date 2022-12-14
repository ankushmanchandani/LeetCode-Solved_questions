
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null){
            return null;
        }
        if(l1 == null && l2 != null){
            return l2;
        }
         if(l1 != null && l2 == null){
            return l1;
        }
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        while(l1 != null && l2 != null){
            if(l1.val > l2.val){
                tail.next = l2;
                l2 = l2.next;
            }
            else{
                tail.next = l1;
                l1 = l1.next;
            }
            tail = tail.next;
        }
        if(l1 != null){
            tail.next = l1;
        }
        if(l2 != null){
            tail.next = l2;
        }
        return dummy.next;
    }
}