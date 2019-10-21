
/**
 *
 * @author NITHISHKUMAR K R
 */
import java.util.*;
class implementation_bubbleSort{
    private int i,j,length;
    public void sort(int arr[]){
        length = arr.length;
        int temp;
        
        for(i=length-1;i>=0;i--){
            for(j=1;j<length;j++){
                if(arr[j-1]>arr[j]){
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        System.out.println("bubble sort completed");
    }
    public void display(int arr[]){
        for(i=0;i<length;i++){
            System.out.print(arr[i]+"\t");
        }
        System.out.println("");
    }
}
public class BubbleSort_1 {
       public static void main(String args[]){
           System.out.println("Bubble Sorting");
           Scanner sc = new Scanner(System.in);
           System.out.print("Number of elements: ");
           int n = sc.nextInt();
           int arr[] = new int[n];
           System.out.println("Enter elements: ");
           for(int i=0;i<n;i++){
               System.out.print("arr["+i+"]: ");
               arr[i] = sc.nextInt();
           }
           implementation_bubbleSort obj = new implementation_bubbleSort();
           obj.sort(arr);
           obj.display(arr);
       }
}
