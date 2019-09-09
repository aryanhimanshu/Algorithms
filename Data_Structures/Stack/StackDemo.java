class Node {
    public int item;
    public Node next;

    public Node(int val) {
        item = val;
    }
}

class Stack {
    public Node root = null;

    /**
     * checks if the stack is empty
     * @return boolean on weather the stack is empty
     */
    public boolean isEmpty() {
        if (root == null)
            return true;

        return false;
    }

    /**
     * pushes (adds) number to stack
     * @param num
     */
    public void push(int num) {
        Node toPush = new Node(num);

        toPush.next = root;
        root = toPush;
    }

    /**
     * peeks at item on top of the stack
     * @return item on to of stack without removing it
     */
    public int peek(){
        return root.item;
    }

    /**
     * pops (removes) number off top of stack
     * @return number on top of the stack
     */
    public int pop(){
        int toPop = root.item;

        root = root.next;

        return toPop;
    }
}

class StackDemo {
    public static void main(String[] args) {
        Stack stack = new Stack();

        System.out.println("Stacks operate using  FIFO, first in fist out");
        System.out.println("This means that when taking things off a stack");
        System.out.println("they will be in reverse order to when you put them on");
        System.out.println("");
        System.out.println("'push' or add 10, 20, 30 to stack");
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println("result:");
        System.out.println(stackToString(stack));

        System.out.println("");
        System.out.println("");

        System.out.println("'pop' or remove from the stack");
        System.out.println("[" + stack.pop() + "]");
        System.out.println("Stack now looks like this:");
        System.out.println(stackToString(stack));

        System.out.println("");
        System.out.println("");

        System.out.println("Stacks usually also have a 'peek' method");
        System.out.println("peek lets you look at the top of the stack");
        System.out.println("without modifying the stack");
        System.out.println("before peek:");
        System.out.println(stackToString(stack));
        System.out.println("result of peek:");
        System.out.println("[" + stack.peek() + "]");
        System.out.println("after peek:");
        System.out.println(stackToString(stack));
        System.out.println("The stack is unchanged");

    }

    /**
     * prints all the items in a stack out, top is on the left
     * @param stack stack to print out
     * @return string of all numbers in stack
     */
    static private String stackToString(Stack stack){
        String toReturn = "";
        Node currentNode = stack.root;

        while (currentNode != null){
            toReturn += "[" + currentNode.item + "]";
            currentNode = currentNode.next;
        }

        return toReturn;
    }
}
