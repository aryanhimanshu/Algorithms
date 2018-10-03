public class SimultaneousBubbleSort {

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
		if (array != null && leftIndex < rightIndex && leftIndex >= 0 && rightIndex >= 0 && array.length > 0
				&& array.length >= rightIndex) {

			int i = leftIndex;
			while (i < rightIndex) {
				boolean swap = false;
				int left = leftIndex + i;
				int right = rightIndex - i;
				while (left < rightIndex && right > leftIndex) {
					if (array[left] > (array[left + 1])) {
						swap(array, left, left + 1);
						swap = true;
					}
					if (array[right] < (array[right - 1])) {
						swap(array, right, right - 1);
						swap = true;
					}
					left++;
					right--;
				}
				if (!swap) {
					break;
				}
				i++;
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
