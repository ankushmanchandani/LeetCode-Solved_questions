
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool LeftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                int index = LeftToRight ? i : size-i-1;
                
                temp[index] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
            LeftToRight = !LeftToRight;
        }
        return ans;
    }
};