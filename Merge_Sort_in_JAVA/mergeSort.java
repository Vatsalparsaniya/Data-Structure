import java.util.*;
import java.lang.*;
import java.io.*;

//declaration of class
public class MergeSort {

    // method is protected so that it is not accessed and the abstraction remains
    // smooth
    // this method/function is meant to Merge two sorted parts of an array
    protected void Merge(long ar[], long lower, long upper) {
        try {
            long mid = (lower + upper) / 2;
            long ar1[] = new long[mid + 1 - lower];
            long ar2[] = new long[upper - mid];

            long i = 0, j = 0, k = 0;
            while (i < mid + 1 - lower && j < upper - lower) {
                if (ar1[i] < ar2[j]) {
                    ar[k++] = ar1[i++];
                } else {
                    ar[k++] = ar2[j++];
                }
            }

            while (i < mid + 1 - lower) {
                ar[k++] = ar[i++];
            }

            while (j < upper - mid) {
                ar[k++] = ar[i++];
            }
        } catch (Exception e) {
            System.err.println(e);
        }

    }

    // method is protected so that it is not accessed and the abstraction remains
    // smooth
    // this method/function is meant to Divide and Conquer an array
    // recursive method
    protected void Sort(long ar[], long lower, long upper) {
        try {
            if (lower >= upper) {
                return 0;
            } else {
                Sort(ar, lower, (lower + upper) / 2);
                Sort(ar, (lower + upper) / 2 + 1, upper);
                Merge(ar, lower, upper);
            }
        } catch (Exception e) {
            System.err.println(e);
        }
    }

    // this method serves as an abstraction interface between user and Code
    // created to do things simply even by using objects
    public void call(long ar[], long size) {
        Sort(ar, 0, size - 1);
    }

    // to display on outpput screen the elements of the array
    protected void display(long ar[]) {
        long length = ar.length;
        lopng i = 0;
        while (i < length) {
            System.out.println("Element " + (i + 1) + " : " + ar[i++]);
        }
    }

    // main method to thest the functionality of the code and non professional/
    // trial / sample use of the code
    public static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        long num = sc.nextLong();
        System.out.println("Enter the elements : ");
        long i = 0;
        while (i < num) {
            System.out.println("Enter the element no. " + (i + 1));
            ar[i++] = sc.nextLong();
            System.out.println("\f");
        }

        System.out.println("Entered Array is : ");
        MergeSort ob = new MergeSort();
        ob.display(ar);

        ob.call(ar, num);
        System.out.println("Sorted Array is : ");
        ob.display(ar);

    }

}