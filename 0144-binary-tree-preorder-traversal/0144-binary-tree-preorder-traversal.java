
class Solution {
    public static void preorder(TreeNode root, List<Integer> in){
        if(root == null) return;
        //root left right
        in.add(root.val);
        preorder(root.left,in);
        preorder(root.right,in);
        
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> pre = new ArrayList<>();
        preorder(root,pre);
        return pre;
    }
}