/**
 * Created by Carlos on 13/10/2017.
 */
public class StackImpl {

    private int stackSize;
    private int[] stackArr;
    private int top;

    /**
     * constructor to create stack with size
     * @param size
     */
    public StackImpl(int size) {
        this.stackSize = size;
        this.stackArr = new int[stackSize];
        this.top = -1;
    }

    /**
     * This method adds new entry to the top
     * of the stack
     * @param entry
     * @throws Exception
     */
    public void push(int entry) throws Exception {
        if(this.isStackFull()){
            throw new Exception("Stack is already full. Can not add element.");
        }
        System.out.println("Adding: "+entry);
        this.stackArr[++top] = entry;
    }

    /**
     * This method removes an entry from the
     * top of the stack.
     * @return
     * @throws Exception
     */
    public int pop() throws Exception {
        if(this.isStackEmpty()){
            throw new Exception("Stack is empty. Can not remove element.");
        }
        int entry = this.stackArr[top--];
        System.out.println("Removed entry: "+entry);
        return entry;
    }

    /**
     * This method returns top of the stack
     * without removing it.
     * @return
     */
    public int peek() {
        return stackArr[top];
    }

    /**
     * This method returns true if the stack is
     * empty
     * @return
     */
    public boolean isStackEmpty() {
        return (top == -1);
    }

    /**
     * This method returns true if the stack is full
     * @return
     */
    public boolean isStackFull() {
        return (top == stackSize - 1);
    }

    public static void main(String[] args) {
        StackImpl stack = new StackImpl(5);
        try {
            stack.push(4);
            stack.push(8);
            stack.push(3);
            stack.push(89);
            stack.pop();
            stack.push(34);
            stack.push(45);
            stack.push(78);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try {
            stack.pop();
            stack.pop();
            stack.pop();
            stack.pop();
            stack.pop();
            stack.pop();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
