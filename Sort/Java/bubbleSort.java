//bubble sort implementation in java
import java.util.*;

public class tester {
	
	//function that takes input array and its size and prints sorted form
	public static void bubble(int [] arr,int n){
		
	//iterating over the array in typical bubble sort fashion swapping wherever needed to get sorted array	
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(arr[j]>arr[k]){
					int temp=arr[j];
					arr[j]=arr[k];
					arr[k]=temp;
				}
			}
		}
		System.out.println("Sorted array is");
		for(int j=0;j<n;j++){
			System.out.print(arr[j]+" ");
		}
	}
	public static void main(String[] args) {
		
		Scanner sc= new Scanner (System.in);
		
			System.out.println("Enter size of array to be sorted");
			int n=sc.nextInt();
			
			System.out.println("Enter elements of array");
			
			int[] arr=new int[n];
			for(int j=0;j<n;j++){
				arr[j]=sc.nextInt();
			}
			
			bubble(arr,n);
		
	}

}
