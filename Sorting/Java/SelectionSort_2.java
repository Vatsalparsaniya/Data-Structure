package Sorting;
/**
 *
 * @author NITHISHKUMAR K R
 */
import java.util.*;
class implementation_selectionSort{
    int i,j,length,temp;
    public void sort(int arr[]){
        length = arr.length;
        
        for(i=0;i<length-1;i++){
            int min = i;
            for(j=i+1;j<length;j++){
                if(arr[j]<arr[min])
                    min = j;
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        System.out.println("selection sort completed");
    }
}
public class SelectionSort_2 {
    public static void main(String args[]){
        System.out.println("Selection Sorting");
           Scanner sc = new Scanner(System.in);
           System.out.print("Number of elements: ");
           int n = sc.nextInt();
           int arr[] = new int[n];
           System.out.println("Enter elements: ");
           for(int i=0;i<n;i++){
               System.out.print("arr["+i+"]: ");
               arr[i] = sc.nextInt();
           }
           implementation_selectionSort obj = new implementation_selectionSort();
           obj.sort(arr);
           implementation imp = new implementation();
           imp.display(arr);
    }
}
