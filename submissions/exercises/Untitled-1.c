/**
 *
 * @author matth
 */

import java.util.Queue;
import java.util.LinkedList;

public class TreesTraversal {

    public static class Node<T> {
        public Node<T> left;
        public Node<T> right;
        public T data;

        public Node(T data) {
            this.data = data;
        }

        public Node<T> getLeft() {
            return this.left;
        }

        public void setLeft(Node<T> left) {
            this.left = left;
        }

        public Node<T> getRight() {
            return this.right;
        }

        public void setRight(Node<T> right) {
            this.right = right;
        }
    }

    public static void preorder(Node<?> n, int level) {
        if (n != null) {
            System.out.print("(" + n.data + " at level " + level + ") ");
            preorder(n.getLeft(), level + 1);
            preorder(n.getRight(), level + 1);
        }
    }

    public static void inorder(Node<?> n, int level) {
        if (n != null) {
            inorder(n.getLeft(), level + 1);
            System.out.print("(" + n.data + " at level " + level + ") ");
            inorder(n.getRight(), level + 1);
        }
    }

    public static void postorder(Node<?> n, int level) {
        if (n != null) {
            postorder(n.getLeft(), level + 1);
            postorder(n.getRight(), level + 1);
            System.out.print("(" + n.data + " at order " + level + ") ");
        }
    }

    public static void levelorder(Node<?> n) {
        Queue<Node<?>> nodequeue = new LinkedList<>();
        int level = 1; // Initialize the level
        if (n != null)
            nodequeue.add(n);
        while (!nodequeue.isEmpty()) {
            int nodesAtCurrentLevel = nodequeue.size();

            System.out.print("Level " + level + ": ");
            for (int i = 0; i < nodesAtCurrentLevel; i++) {
                Node<?> next = nodequeue.remove();
                System.out.print("(" + next.data + ") ");

                if (next.getLeft() != null) {
                    nodequeue.add(next.getLeft());
                }
                if (next.getRight() != null) {
                    nodequeue.add(next.getRight());
                }
            }
            System.out.println(); // Move to the next line for the next level
            level++;
        }
    }

    public static void main(final String[] args) {
        Node<Integer> one = new Node<>(1);
        Node<Integer> two = new Node<>(2);
        Node<Integer> three = new Node<>(3);
        Node<Integer> four = new Node<>(4);
        Node<Integer> five = new Node<>(5);
        Node<Integer> six = new Node<>(6);
        Node<Integer> seven = new Node<>(7);
        Node<Integer> eight = new Node<>(8);
        Node<Integer> nine = new Node<>(9);

        one.setLeft(two);
        one.setRight(three);
        two.setLeft(four);
        two.setRight(five);
        three.setLeft(six);
        four.setLeft(seven);
        six.setLeft(eight);
        six.setRight(nine);

        System.out.print("PreOrder: ");
        preorder(one, 1);
        System.out.println();
        System.out.print("InOrder: ");
        inorder(one, 1);
        System.out.println();
        System.out.print("Post Order: ");
        postorder(one, 1);
        System.out.println();
        System.out.println();
        System.out.println("Level Order:");
        levelorder(one);
    }
}
