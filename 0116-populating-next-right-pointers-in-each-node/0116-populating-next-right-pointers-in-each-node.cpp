
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        auto L = root->left,R=root->right  , N = root->next;
        if(L){
            L->next = R;
            if(N) R->next = N->left;
            connect(L);
            connect(R);
        }
        return root;
    }
};