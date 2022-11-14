
class Solution {
public:
    ListNode* mergeSort(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        
        while(l1!=NULL && l2!=NULL){
            
            if(l1->val > l2->val){
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
            else{
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            
        }
        
        if(l1 == NULL){
            tail->next = l2;
        }
        else{
            tail->next = l1;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(fast!=NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        
        return mergeSort(l1,l2);
    }
};