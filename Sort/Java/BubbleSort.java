public class BubbleSort {

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
		if (array != null && leftIndex < rightIndex && leftIndex >= 0 && rightIndex >= 0 && array.length > 0
				&& array.length >= rightIndex) {

			int i = leftIndex;
			while (i < rightIndex) {
				boolean temTroca = false;
				for (int y = leftIndex; y < rightIndex - i; y++) {
					if (array[y] > (array[y + 1])) {
						swap(array, y, y + 1);
						temTroca = true;
					}
				}
				if (!temTroca) {
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
