public class Quicksort {

    public static void quicksort(int array[]) {
        quicksort(array,0,array.length-1);
    }

    public static void quicksort(int array[], int left, int right) {
        int index;

        if (array.length > 1) {
            index = partition(array,left,right);

            if (left < index-1) {
                quicksort(array, left, index - 1);
            }

            if (index < right) {
                quicksort(array, index, right);
            }
        }
    }

    private static int partition(int array[], int left, int right) {
        int pivot = array[(int)Math.floor((right+left)/2)];
        int i = left;
        int j = right;

        while (i <= j) {
            while (array[i] < pivot) {
                i++;
            }
            while (array[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        return i;
    }

    private static void swap(int array[], int firstIndex, int secondIndex) {
        int temp = array[firstIndex];
        array[firstIndex] = array[secondIndex];
        array[secondIndex] = temp;
    }

    public static void main(String a[]){
        int[] arr1 = {9,14,3,2,43,11,58,22};
        System.out.println("Before Insertion Sort");
        for(int i:arr1){
            System.out.print(i+" ");
        }
        System.out.println();

        quicksort(arr1);//sorting array using insertion sort

        System.out.println("After Insertion Sort");
        for(int i:arr1){
            System.out.print(i+" ");
        }
    }

}