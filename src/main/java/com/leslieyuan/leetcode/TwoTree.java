package com.leslieyuan.leetcode;

public class TwoTree {
    static class TreeNode {
        Integer val;
        TreeNode left;
        TreeNode right;

        TreeNode(int _val) {
            val = _val;
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(7);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(6);
        root.right = new TreeNode(5);
        root.right.right = new TreeNode(9);

        preOderTraversal(root);
    }

    public static void preOderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }
        System.out.println(root.val);
        if (root.left != null) {
            preOderTraversal(root.left);
        }
        if (root.right != null) {
            preOderTraversal(root.right);
        }
    }
}
