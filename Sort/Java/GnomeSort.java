public class GnomeSort {

	public static void main(String a[]) {
		int[] arr1 = { 9, 14, 3, 2, 43, 11, 58, 22 };
		System.out.println("Before Sort");
		for (int i : arr1) {
			System.out.print(i + " ");
		}
		System.out.println();

		sort(arr1, 0, arr1.length - 1);// sorting array using insertion sort

		System.out.println("After Sort");
		for (int i : arr1) {
			System.out.print(i + " ");
		}
	}

	public static void sort(int[] array, int leftIndex, int rightIndex) {
		if (array.length > 0 && leftIndex >= 0 && rightIndex < array.length && leftIndex < rightIndex) {

			int pivot = leftIndex + 1;
			while (pivot <= rightIndex) {
				if (pivot == leftIndex || array[pivot] >= (array[pivot - 1])) {
					pivot++;
				} else {
					swap(array, pivot, pivot - 1);
					pivot--;
				}
			}
		}
	}

	public static void swap(int[] array, int i, int j) {
		if (array == null)
			throw new IllegalArgumentException();

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
