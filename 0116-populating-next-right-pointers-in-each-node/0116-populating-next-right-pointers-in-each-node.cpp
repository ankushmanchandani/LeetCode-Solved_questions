
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(size(q)){
            Node* rightnode = NULL;
            for(int i=q.size();i;i--){
                auto cur = q.front(); q.pop();
                cur->next = rightnode;
                rightnode = cur;
                if(cur->right){
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};




