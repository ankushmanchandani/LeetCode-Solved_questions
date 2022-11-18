
class Solution {
    public static void inorder(TreeNode root, List<Integer> in){
        if(root == null){
            return ;
        }
        inorder(root.left,in);
        in.add(root.val);
        inorder(root.right,in);
        
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        //left root right 
        List<Integer> in = new ArrayList<>();
        
        inorder(root,in);
        return in;
    }
}