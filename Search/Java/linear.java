//linear search implementation in java.
import java.util.*;
public class linearsearch {
	
	//this is the linear function that takes input array and finds the element and prints outpu accordingly
	public static void linear(int[] arr,int x){
		
		int n=arr.length,index=0,flag=0;
		
		//main for loop where the array is traversed and in case element is found a variable called flag is used to indicate so.
		//Also the position of variable is stored in a variable index.
		for(int i=0;i<n;i++){
			if(arr[i]==x){
				flag=1;
				index=i;
				break;
			}
		}
		
		//finally if the flag indicates that the variable was found during traversal,the value of index is printed otherwise element not found is printed.
		//NOTE:In java arrays are traditionally zero indexed and that has been used in this code.
		if(flag==1){
			System.out.println(x + " was found at position "+ index);
		}
		else{
			System.out.println("Element not found");
		}
		
	}

	public static void main(String[] args) {
		
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
		//call to function linear to find whether the element x is actually present in array or not
		linear(arr,x);
		
	}

}

