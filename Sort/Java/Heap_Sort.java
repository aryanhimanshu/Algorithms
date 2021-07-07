public class HeapSort {
 
 public static void main(String[] args) {
  int[] array = new int[]{4, 10, 3, 5, 1};
   
  new HeapSort().sort(array);
   
  for (int i : array) {
   System.out.print(i + " ");
  } 
 }
 
 public void sort(int data[]) {
  int size = data.length;
   
  for (int i = size / 2 - 1; i >= 0; i--) {
   heapify(i, data, size);
  }
 
  for(int i=data.length-1;i>=0;i--){
   int temp = data[0];
   data[0]=data[i];
   data[i]=temp;
 
   //reduce the heap window by 1
   size  = size-1;
 
   //call max heapify on the reduced heap
   heapify(0, data, size);
  }
 }
 
 private int leftChild(int i){ 
  return 2 * i + 1; 
 }
 private int rightChild(int i) { 
  return 2 * i + 2; 
 }
 
 private void heapify(int i, int[] data, int size) {
  int largestElementIndex = i;
 
  int leftChildIndex = leftChild(i);
  if (leftChildIndex < size && data[leftChildIndex] > data[largestElementIndex]) {
   largestElementIndex = leftChildIndex;
  }
 
  int rightChildIndex = rightChild(i);
  if (rightChildIndex < size && data[rightChildIndex] > data[largestElementIndex]) {
   largestElementIndex = rightChildIndex;
  }
 
  if (largestElementIndex != i) {
   int swap = data[i];
   data[i] = data[largestElementIndex];
   data[largestElementIndex] = swap;
 
   // Recursively heapify the affected sub-tree
   heapify(largestElementIndex, data, size);
  }
 }
 
}
