public class CountingSort {

	public static void main(String a[]) {
		int[] arr1 = { 9, 14, 3, 2, 43, 11, 58, 22 };
		System.out.println("Before Sort");
		for (int i : arr1) {
			System.out.print(i + " ");
		}
		System.out.println();

		sort(arr1, 0, arr1.length-1);// sorting array using insertion sort

		System.out.println("After Sort");
		for (int i : arr1) {
			System.out.print(i + " ");
		}
	}


	public static void sort(int[] array, int leftIndex, int rightIndex) {
		if (array.length > 0 && leftIndex >= 0 && rightIndex < array.length && leftIndex < rightIndex) {

			int biggest = biggest(array, leftIndex, rightIndex);

			int[] count = new int[biggest + 1];
			
			for (int i = leftIndex; i <= rightIndex; i++) {
				count[array[i]]++;
			}

			for (int i = 1; i < count.length; i++) {
				count[i] += count[i - 1];
			}

			Integer[] answer = new Integer[array.length];
			
			for (int i = leftIndex; i <= rightIndex; i++) {
				answer[count[array[i]] - 1] = array[i];
				count[array[i]]--;
			}

			for (int i = leftIndex; i <= rightIndex; i++) {
				array[i] = answer[i];
			}
		}
	}

	public static int biggest(int[] array, int leftIndex, int rightIndex) {
		int biggest = array[leftIndex];

		for (int i = leftIndex; i <= rightIndex; i++) {
			if (array[i] > biggest)
				biggest = array[i];
		}
		return biggest;
	}

	public static void swap(int[] array, int i, int j) {
		if (array == null)
			throw new IllegalArgumentException();

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
