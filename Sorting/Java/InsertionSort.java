
import java.util.*;
public class InsertionSort{
	public static int i,j,element;
	
	public static void sort(int arr[]){
		int length = arr.length;
		for(i=1;i<length;i++){
			element = arr[i];
			j = i;
			while(j>0&& arr[j-1]>element){
				arr[j] = arr[j-1];
				j--;
			}
			arr[j] = element;
		}
	}
	public static void display(int arr[]){
		for(i=0;i<arr.length;i++){
			System.out.print(arr[i]+"\t");
		}
		System.out.println("");
	}
	
	public static void main(String arg[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = sc.nextInt();
		sort(arr);
		display(arr);
	}
}