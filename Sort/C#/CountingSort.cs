using System;
using System.Linq;

namespace CountingSort
{
    class CountingSort
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
            // k represents the largest integer in A. It is used for creating the array C[0..k]. 
            // The + 1 is due to C# arrays being zero-indexed.
            // B will be the sorted array
            int k = A.Max() + 1;
            int[] B = new int[A.Length];
            int[] C = new int[k];

            // At first the C arrays needs to consist of only zeroes, 
            //since each element will be counted up later based on the integers in A.
            for (int i = 0; i < k; i++)
            {
                C[i] = 0;
            }

            for (int j = 0; j < A.Length; j++)
            {
                C[A[j]] += 1;
            }
            // C[i] now contains the number of elements equal to i

            for (int i = 1; i < k; i++)
            {
                C[i] = C[i] + C[i - 1];
            }
            // C[i] now contains the number of elements less than or equal to i

            // Based on the C array, the numbers from A is now placed into the correct position in B.
            for (int j = A.Length - 1; j >= 0; j--)
            {
                B[C[A[j]] - 1] = A[j];
                C[A[j]] -= 1;
            }

            return B;
        }

        private static void PrintArray(string name, int[] arr, bool isSorted)
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
