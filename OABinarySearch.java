//Order agnostic binary search : Used when order of sorted array is not given
import java.util.Scanner;

//Java implementation of non-recursive order agnostic binary search

public class OABinarySearch
{
  
  // Return the index of x if it is present in array, else
  // return -1
  
  public static int binarySearch(int[] arr, int target)
  {
    
    int start = 0;
    int end = arr.length-1;
    
    // To check whether array is sorted in ascending order or not
    boolean isAscending = arr[start] < arr[end];
    
    while( start <= end )
    {
      int middle = start + (end - start)/2;
      
      // If element is present at the middle itself
      if(arr[middle] == target)
        return middle;
      
      // If array is sorted in ascending order
      if(isAscending)
      {
        if(arr[middle]<target)
          start = middle + 1;
        else
          end = middle - 1;
      }
      
      // If array is sorted in descending order
      else
      {
        if(arr[middle]>target)
          start = middle + 1;
        else
          end = middle - 1;
      }
    }
    
    // If element is not present
    return -1;
  }
  
  // Driver method to test above
  public static void main(String args[])
  {
    
    Scanner sc=new Scanner(System.in);
    
    int size, target;
    
    System.out.println("Enter the size of array");
    size = sc.nextInt();
    
    int[] arr = new int[size];
    System.out.println("Enter the numbers for the array");
    for(int i = 0 ; i<size ; i++)
    {
      arr[i] = sc.nextInt();
    }
    
    System.out.println("Enter the number to be searched");
    target = sc.nextInt();
    
    int result = binarySearh(arr, target);
    if(result == -1)
      System.out.println("Element not present");
    else
      System.out.println("Element found at index " + result);
  }
}
 
