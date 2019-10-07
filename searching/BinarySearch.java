import java.util.Scanner;

public class BinarySearch {

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
        int ans = BinarySearch(arr, n);
        if (ans = -1) {
            System.out.println("Number not found");
        } else {
            System.out.println(ans);
        }

    }

    public static int BinarySearch(int[] arr1, int data) {
        int left = 0;
        int mid;
        int right = arr1.length - 1;
        while (left <= right) {
            mid = (right + left) / 2;
            if (arr1[mid] == data) {
                return mid;
            } else if (arr1[mid] >= data) {
                right = mid - 1;
                if (arr1[right] == data) {
                    return right;
                }
            } else {
                left = mid + 1;
                if (arr1[left] == data) {
                    return left;
                }
            }
            left++;
        }
        return -1;
    }

}
