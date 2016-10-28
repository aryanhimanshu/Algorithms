import java.util.Scanner;

// Java implementation of recursive Binary Search
public class binarysearch
{
    // Returns index of x if it is present in arr[l..r], else
    // return -1
		public static int binarySearch(int arr[], int l, int r, int x)
    {
        if (r>=l)
        {
            int mid = l + (r - l)/2;
 
            // If the element is present at the middle itself
            if (arr[mid] == x)
               return mid;
 
            // If element is smaller than mid, then it can only
               if (arr[mid] > x)
               return binarySearch(arr, l, mid-1, x);
 
            // Else the element can only be present in right
            // subarray
            return binarySearch(arr, mid+1, r, x);
        }
 
        // We reach here when element is not present in array
        return -1;
    }
 
    // Driver method to test above
    public static void main(String args[])
    {
    Scanner sc=new Scanner(System.in);
		
		int n,x;
		
		System.out.println("Enter the length of array");
		
		n=sc.nextInt();
		int[] arr=new int[n];
		
		System.out.println("Enter the numbers for the array");
		
		for(int i=0;i<n;++i){
			arr[i]=sc.nextInt();
		}
		
		System.out.println("Enter the number to be searched");
		
		x=sc.nextInt();
        int result = binarySearch(arr,0,n-1,x);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index "+result);
    }
}
