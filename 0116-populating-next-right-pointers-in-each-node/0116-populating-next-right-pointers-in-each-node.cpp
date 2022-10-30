
class Solution {
public:
    Node* connect(Node* root) {
        auto head = root;
        for(;root;root=root->left){
            for(auto cur=root;cur;cur=cur->next){
                if(cur->left){
                    cur->left->next=cur->right;
                
                    if(cur->next){
                        cur->right->next = cur->next->left;
                    }
                }
                else break;
            }
        }
        return head;
    }
};