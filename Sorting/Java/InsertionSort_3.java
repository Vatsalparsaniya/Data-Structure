
import java.util.Scanner;

/**
 *
 * @author NITHISHKUMAR K R
 */
class implementation_insertionSort{
    int i,j,length;
    public void sort(int arr[]){
        length = arr.length;
        for(i=1;i<length;i++){
            int element = arr[i];
            j = i;
            while(j>0 && arr[j-1]>element){
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = element;
        }
        System.out.println("Insertion sorting completed");
    }
}
public class InsertionSort_3 {
    public static void main(String arg[]){
        System.out.println("Insertion Sorting");
           Scanner sc = new Scanner(System.in);
           System.out.print("Number of elements: ");
           int n = sc.nextInt();
           int arr[] = new int[n];
           System.out.println("Enter elements: ");
           for(int i=0;i<n;i++){
               System.out.print("arr["+i+"]: ");
               arr[i] = sc.nextInt();
           }
           implementation_insertionSort obj = new implementation_insertionSort();
           obj.sort(arr);
           implementation imp = new implementation();
           imp.display(arr);
    }
}
