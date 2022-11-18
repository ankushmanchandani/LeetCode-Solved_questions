
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new LinkedList<List<Integer>>() ;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        
        if(root==null) return list;
        q.offer(root);
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> l = new LinkedList<>();
            for(int i=0;i<size;i++){
                TreeNode node = q.peek();
                q.poll();
                if(node.left != null) q.offer(node.left);
                if(node.right != null) q.offer(node.right);
                l.add(node.val);
            }
            list.add(l);
        }
        return list;
    }
}