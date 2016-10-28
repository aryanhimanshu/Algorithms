using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuickSort
{
    class Program
    {
        static int ChoosePivotMedian(int[] inputArray, int left, int right)
        {
            int first = inputArray[left];
            int middle = inputArray[((right - left) / 2) + left];
            int last = inputArray[right];
            if (first >= middle && first <= last || first <= middle && first >= last)
            {
                return left;
            }
            else if (middle >= first && middle <= last || middle <= first && middle >= last)
            {
                return ((right - left) / 2) + left;
            }
            else if (last >= first && last <= middle || last <= first && last >= middle)
            {
                return right;
            }
            return 0;
        }
        static int Partition(int[] inputArray, int left, int right)
        {
            int i = left + 1;
            for (int j = i; j <= right; j++)
            {
                if (inputArray[left] > inputArray[j])
                {
                    Swap(j, i, inputArray);
                    i++;
                }
            }
            Swap(i - 1, left, inputArray);
            return i - 1;
        }
        static void Swap(int a, int b, int[] inputArray)
        {
            int temp = inputArray[a];
            inputArray[a] = inputArray[b];
            inputArray[b] = temp;
        }
        static void QuickSort(int[] inputArray, int left, int right, Func<int[], int, int, int> PivotDelegate)
        {
            if (left >= right) return;
            int pivot = PivotDelegate(inputArray, left, right);
            Swap(pivot, left, inputArray);
            int PivotPosition = Partition(inputArray, left, right);
            QuickSort(inputArray, left, PivotPosition - 1, PivotDelegate);
            QuickSort(inputArray, PivotPosition + 1, right, PivotDelegate);
        }