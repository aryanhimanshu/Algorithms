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
			
			System.out.println("Element array is 5, 3, 2, 6, 7, 9");
			
			int[] arr=new int[5, 3, 2, 6, 7, 9];
			for(int j=0;j<n;j++){
				arr[j]=sc.nextInt();
			}
			
			bubble(arr,n);
	}

}
