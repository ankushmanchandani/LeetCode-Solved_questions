
class Solution {
public:
    int count=0;
    void solve(TreeNode* root,long long cursum, int k, unordered_map<long,int> &mpp){
        if(root == NULL) return ;
        cursum += root->val;
        // if(cursum == k) count++;
        if(mpp.count(cursum - k)) count += mpp[cursum-k];
        mpp[cursum]++;
        solve(root->left,cursum,k,mpp);
        solve(root->right,cursum,k,mpp);
        mpp[cursum]--;
        cursum-=root->val;;
    }
    int pathSum(TreeNode* root, int k) {
        unordered_map<long,int> mpp;
        long long cursum = 0;
        mpp[0]=1;
        solve(root,cursum,k,mpp);
        return count;
    }
};