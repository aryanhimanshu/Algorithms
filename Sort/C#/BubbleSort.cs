using System;

namespace BubbleSort
{
    class BubbleSort
    {
        public static void Main()
        {
            int[] testA = { 4, 3, 2, 1 };
            int[] testB = { 5, 5, 4, 1, 7 };

            PrintArray("testA", testA, false);
            PrintArray("sortedA", Sort(testA), true);

            PrintArray("testB", testB, false);
            PrintArray("sortedB", Sort(testB), true);
        }

        public static int[] Sort(int[] A)
        {
            for (int i = 0; i < A.Length; i++)
            {
                for (int j = A.Length - 1; j > i; j--)
                {
                    if (A[j] < A[j - 1])
                    {
                        // Swaps the two elements
                        var temp = A[j];
                        A[j] = A[j - 1];
                        A[j - 1] = temp;
                    }
                }
            }
            return A;
        }

        static void PrintArray(string name, int[] arr, bool isSorted)
        {
            Console.Write($"Array: {name}\nIs sorted: {isSorted}\n[");
            for (int i = 0; i < arr.Length; i++)
            {
                if (i == arr.Length - 1)
                {
                    Console.Write($" {arr[i]} ]\n\n");
                }
                else
                {
                    Console.Write($" {arr[i]}, ");
                }
            }
        }

    }
}
