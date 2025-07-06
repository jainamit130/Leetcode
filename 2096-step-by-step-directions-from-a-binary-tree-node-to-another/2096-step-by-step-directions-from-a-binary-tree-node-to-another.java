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
    public String getDirections(TreeNode root, int startValue, int destValue) {
        return combine2Paths(dfs(root,startValue,new StringBuilder()),dfs(root,destValue,new StringBuilder()));
    }

    public String dfs(TreeNode root, int val,StringBuilder path) {
        if (root == null) return "";
        if (root.val == val) return path.toString();
        String left = dfs(root.left,val,path.append("L"));
        if(left!="") return left;
        path.deleteCharAt(path.length()-1); 
        String right = dfs(root.right,val,path.append("R"));
        if(right!="") return right;
        path.deleteCharAt(path.length()-1); 
        return "";
    }

    
    public String combine2Paths(String s1,String s2) {
        int i=0;int j=0;
        StringBuilder s3 = new StringBuilder();
        while(i<s1.length() && j<s2.length()) {
            if(s1.charAt(i)==s2.charAt(j)) {
                i++;j++;
            } else break;
        }
        while(i<s1.length()) {s3.append("U");i++;}
        if(j<s2.length()) s3.append(s2.substring(j));
        return s3.toString();
    }
}