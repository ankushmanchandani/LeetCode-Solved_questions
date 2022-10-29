
class Solution {
public:
    ListNode* find_min(ListNode* head){
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL)
            prev->next =NULL;
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) 
            return NULL;
        
        ListNode* mid = find_min(head);
        TreeNode* root = new TreeNode(mid->val);
        
        if(head == mid)
            return root;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        
        return root;
        
    }
};