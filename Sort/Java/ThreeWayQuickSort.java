
public class ThreeWayQuickSort {

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

		if (array.length > 1 && leftIndex < rightIndex) {
			int[] resposta = partition(array, leftIndex, rightIndex);
			sort(array, leftIndex, resposta[0] - 1);
			sort(array, resposta[1] + 1, rightIndex);
		}
	}

	private static int[] partition(int[] array, int leftIndex, int rightIndex) {
		int j = leftIndex;
		int k = rightIndex;
		int nPivot = array[leftIndex];
		int i = leftIndex;

		while (i <= k) {
			if (array[i] == (nPivot))
				++i;
			else if (array[i] > (nPivot))
				swap(array, i, k--);
			else {
				swap(array, i++, j++);
			}
		}

		int[] resposta = { j, k };
		return resposta;
	}

	public static void swap(int[] array, int i, int j) {
		if (array == null)
			throw new IllegalArgumentException();

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
