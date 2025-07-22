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
    int ans = 0;
    public int maxProduct(TreeNode root) {
        int total = getTotal(root);
        solve(root,total);
        return ans;
    }

    int solve(TreeNode root,int total) {
        if(root==null) return 0;
        int sum = root.val + solve(root.left,total) + solve(root.right,total);
        ans = Math.max(ans,(total-sum)*sum);
        return sum;
    }

    public int getTotal(TreeNode root) {
        if(root==null) return 0;
        return root.val + getTotal(root.left) + getTotal(root.right);
    }
}