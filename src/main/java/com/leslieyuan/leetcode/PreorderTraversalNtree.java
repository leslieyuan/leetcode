package com.leslieyuan.leetcode;

import java.util.*;

/**
 * leetcode #589
 * N-ary Tree Preorder Traversal
 */
public class PreorderTraversalNtree {
    public static void main(String[] args) {
    }

    // Stack pre-order traversal
    public List<Integer> preorderNoRecur(Node root) {
        if (root == null) {
            return Collections.emptyList();
        }
        Stack<Node> s = new Stack<>();
        s.push(root);
        List<Integer> res = new ArrayList<>();
        while (!s.isEmpty()) {
            root = s.pop();
            res.add(root.val);
            for (int i = root.children.size() - 1; i >= 0; --i) {
                Node node = root.children.get(i);
                if (node != null) {
                    s.push(node);
                }
            }
        }
        return res;
    }

    // Recursive pre-order traversal
    public List<Integer> preorder(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        res.add(root.val);
        if (root.children == null) {
            return res;
        }
        for (Node node : root.children) {
            res.addAll(preorder(node));
        }
        return res;
    }

    // Definition for a Node.
    static class Node {
        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }
}


