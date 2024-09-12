
import java.util.*;

public class BinarySearchTree {

    static class Node {

        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;

        }

    }

    Node root;

    BinarySearchTree(int data) {
        root = new Node(data);
    }

    BinarySearchTree() {
        root = null;
    }

    public void Inorder(Node root) {

        if (root != null) {
            Inorder(root.left);
            System.out.println(root.data);
            Inorder(root.right);
        }

    }

    public Node insert(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;

        } else if (root.data > data) {
            root.left = insert(root.left, data);
        } else {
            root.right = insert(root.right, data);
        }

        return root;

    }

    public boolean Search(Node root, int data) {

        if (root != null) {
            if (root.data == data) {
                return true;
            } else if (root.data < data) {
                return Search(root.right, data);
            } else {
                return Search(root.left, data);
            }

        }
        return false;

    }

    public static void main(String args[]) {

        BinarySearchTree tree = new BinarySearchTree();
        tree.root = new Node(2);
        tree.insert(tree.root, 1);
        tree.insert(tree.root, 3);
        tree.Inorder(tree.root);

    }

}
