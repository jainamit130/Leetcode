/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        return solve(root,k,new HashSet<Integer>());
    }

    boolean solve(TreeNode root,int k,Set<Integer> st) {
        if(root==null) return false;
        boolean ans = solve(root.left,k,st);
        if(st.contains(k-root.val)) return true;
        st.add(root.val);
        ans = ans || solve(root.right,k,st);
        return ans;
    }
}