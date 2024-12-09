import java.util.Arrays;

public interface Stack<T> {

    public static class ArrayStack<T> implements Stack<T> {

        private static final int MINIMUM_SIZE = 1024;

        private T[] array = (T[]) new Object[MINIMUM_SIZE];
        private int size = 0;

        public boolean push(T value) {
            if (size >= array.length)
                grow();
            array[size++] = value;
            return true;
        }

        public T pop() {
            if (size <= 0) return null;

            T t = array[--size];
            array[size] = null;

            int shrinkSize = array.length>>1;
            if (shrinkSize >= MINIMUM_SIZE && size < shrinkSize)
                shrink();

            return t;
        }

        public T peek() {
            if (size <= 0) return null;

            T t = array[--size];
            return t;
        }

        public T get(int index) {
            if (index>=0 && index<size) return array[index];
            return null;
        }

        public boolean remove(T value) {
            for (int i = 0; i < size; i++) {
                T obj = array[i];
                if (obj.equals(value)) {
                    return (remove(i));
                }
            }
            return false;
        }

        private boolean remove(int index) {
            if (index != --size) {
                // Shift the array down one spot
                System.arraycopy(array, index + 1, array, index, size - index);
            }
            array[size] = null;

            int shrinkSize = array.length>>1;
            if (shrinkSize >= MINIMUM_SIZE && size < shrinkSize)
                shrink();

            return true;
        }

        // Grow the array by 50%
        private void grow() {
            int growSize = size + (size<<1);
            array = Arrays.copyOf(array, growSize);
        }

        // Shrink the array by 50%
        private void shrink() {
            int shrinkSize = array.length>>1;
            array = Arrays.copyOf(array, shrinkSize);
        }

        public void clear() {
            size = 0;
        }

        public boolean contains(T value) {
            for (int i = 0; i < size; i++) {
                T obj = array[i];
                if (obj.equals(value))
                    return true;
            }
            return false;
        }

        public int size() {
            return size;
        }

        public boolean validate() {
            int localSize = 0;
            for (int i=0; i<array.length; i++) {
                T t = array[i];
                if (i<size) {
                    if (t==null) return false;
                    localSize++;
                } else {
                    if (t!=null) return false;
                }
            }
            return (localSize==size);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = size - 1; i >= 0; i--) {
                builder.append(array[i]).append(", ");
            }
            return builder.toString();
        }
    }

}

class StackExample {
    public static void main(String[] args){
        Stack<Integer> test = new Stack<Integer>();
        System.out.println("Pushing three elements into the stack");
        test.push(23);
        test.push(12);
        test.push(14);
        System.out.println(test.toString());
        System.out.println("Pushing one more element into the stack");
        demo.insert(76);
        System.out.println(test.toString());
        System.out.println("Popping one element out of the stack");
        test.pop();
        System.out.println(test.toString());
    }
}
