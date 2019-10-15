import java.util.*;

public class QuickSort{
	public static void display(int arr[], int left, int right){
		int i;
		System.out.println("I: "+left+" J: "+right);
		for(i=0;i<arr.length;i++)	
				System.out.print(arr[i]+"\t");
		System.out.println("");
	}

	public static int partition(int arr[], int left, int right){
		int i=left, j=right, temp;

		int pivot = arr[(left+right)/2];
                System.out.println("Pivot: "+pivot);
                  
		while(i<=j){
			while(arr[i]<pivot)
				i++;
			while(arr[j]>pivot)
				j--;
			if(i<=j){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}	
		}
		System.out.println("After Partition: ");
		display(arr, i, j);
		return i;
	}   // <pivot | pivot | >pivot
	
	public static void quickSort(int arr[], int left, int right){
		int index = partition(arr, left, right);
		if(left<index-1){ 
			System.out.println("When left > index-1 :"+left+" > "+(index-1));
			display(arr, left, index-1);
			quickSort(arr, left, index-1);
		}
		if(index<right){
			System.out.println("When right > index :"+right+" > "+index);
			display(arr, index, right);
			quickSort(arr, index, right);
		}
		//display(arr, left, right);
	}
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		//int n = sc.nextInt();
		int i;
		//int arr[] = {18, 11, 19, 98, 7, 10, 70};
		
                int arr[] = {38, 27, 42, 9};
                quickSort(arr, 0, arr.length-1);		
	}
}	
