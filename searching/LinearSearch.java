import java.util.Scanner;

public class LinearSearch {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int n = s.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the " + (i + 1) + "th element");
            arr[i] = s.nextInt();
        }
        int ans = linearsearch(arr, n);
        if (ans = -1) {
            System.out.println("Number not found");
        } else {
            System.out.println(ans);
        }

    }

    public static int linearsearch(int[] arr, int data) {
        int i;
        for (i = 0; i <= arr.length; i++) {
            if (arr[i] == data) {
                return i;
            }

        }
        return -1;

    }

}
