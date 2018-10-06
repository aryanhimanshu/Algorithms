/**
 * A heap is a specialized tree-based data structure that satisfies the heap
 * property. In a max heap, a node is greater than or equal to its children. In
 * a min heap, a node is smaller than or equal to its children. The heap is one
 * maximally efficient implementation of a priority queue.
 * 
 */
public interface Heap<T extends Comparable<T>> {

	/**
	 * Returns true, if the heap is empty, or false, otherwise.
	 * 
	 * @return the boolean that indicates if the heap is empty.
	 * 
	 */
	public boolean isEmpty();

	/**
	 * Returns the number of elements contained in the heap.
	 * 
	 * @return the size of the heap.
	 * 
	 */
	public int size();

	/**
	 * Returns (without removing) the root element of the heap or null if the heap
	 * is empty. When using a min heap, the root element will be the smallest one,
	 * while in a max heap, it will be the greatest one.
	 * 
	 * @return the root element of the heap (or null if the heap is empty).
	 * 
	 */
	public T root();

	/**
	 * Inserts a new element in the heap. Null elements are not allowed. If the
	 * given element is null, the heap will remain unchanged.
	 * 
	 * @param element the element to be inserted.
	 * 
	 */
	public void insert(T element);

	/**
	 * Removes and returns the root element of the heap. If the heap is empty, this
	 * method returns null.
	 * 
	 * @return the root element (or null, if the heap is empty).
	 * 
	 */
	public T extract();

	/**
	 * Builds the heap based on the elements of a given array. If the heap is not
	 * empty when this method is executed, the original elements are lost.
	 * 
	 * @param array the array containing the elements to build the heap.
	 * 
	 */
	public void build(T[] array);

	/**
	 * Returns an array containing all the elements in the heap. The array does not
	 * contain empty spaces (or null elements).
	 * 
	 * @return an array with all non-null elements of the heap.
	 * 
	 */
	public abstract T[] toArray();

}
