//java implementation of merge sort
import java.util.*;
public class merge {
	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter the size of array to be sorted");
		
		int n=sc.nextInt();
		int[] arr=new int[n];
		
		System.out.println("Enter the elements of the array");
		for(int i=0;i<n;i++){
			arr[i]=sc.nextInt();
		}
		Mergesort(arr);
		
		System.out.println("The sorted array is:");
		for(int i=0;i<n;i++){
			System.out.print(arr[i]+" ");
		}
		
		/*
		 * incase input is not to be taken
		 * Following are test values for the code
		 * int [] test=new int [7];
		 * int [] test1={1,3,5};
		 * int[] test2={2,4,6,7};
		 * Merge(test1,test2,test);
		 * for(int i=0;i<test.length;i++){
		 * System.out.println(test[i]);
		}*/
	}
	//Main mergesort function 
	public static  void Mergesort(int[] arr){
		int n=arr.length;
		
		//base condition to stop recursion
		if(n<2){
			return;
		}
		int mid=n/2;
		
		//creating two auxillary arrays
		int[] l=new int[mid];
		int[] r=new int[n-mid];
		
		
		for(int i=0;i<=mid-1;i++){
			l[i]=arr[i];
			//System.out.println(l[i]);
			}
		
			//System.out.println("l");
		
		for(int i=mid;i<n;i++){
			r[i-mid]=arr[i];
		}
		//System.out.println("r");
		
		//recursive calls on the two halfs created
		Mergesort(l);
		Mergesort(r);
		//call to merge function to merge two l and r arrays and form final sorted array
		Merge(l,r,arr);
		
	}
	//Merge function used to merge two sorted arrays in a sorted manner
	public static void Merge(int[] l,int[] r,int[] arr){
		int nl=l.length;
		int nr=r.length;
		int i=0,j=0,k=0;
		//till no auxillary array is exhausted simply compare and merge 
		while(i<nl && j<nr){
			if(l[i]<=r[j]){
				arr[k]=l[i];
				i++;
			}
			else{
				arr[k]=r[j];
				j++;
			}
			k++;
		}
		//if any auxilarry array is exhausted simply enter the remaining elements in the already sorted order
		while(i<nl){
			arr[k]=l[i];
			i++;k++;
		}
		while(j<nr){
			arr[k]=r[j];
			j++;k++;
		}
	
		
		
	}

}
