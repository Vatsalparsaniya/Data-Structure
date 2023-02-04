package Array.Searching;

import java.util.Arrays;
import java.util.Scanner;

public class Binary_search {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);

        System.out.print("Enter how many elements in array:");
        int ele=in.nextInt();
        int[] arr=new int[ele];

        //Getting values from the user for Array
        for (int i = 0; i < ele; i++) {
            System.out.print("Enter "+(i+1)+" value:");
            arr[i]= in.nextInt();
        }
        //The Array
        System.out.println(Arrays.toString(arr));

        System.out.print("Enter the value to search in Array:");
        int key=in.nextInt();

        int pos=binary(arr,key);
        System.out.println(pos!=-1?"Value found in "+pos+" position":"Value not found!!!");

    }

    private static int binary(int[] arr,int key){
        int start=0;
        int end=arr.length-1;
        while (start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>key){
                end=mid-1;
            } else if (arr[mid]<key) {
                start=mid+1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
}

// This code was Contributed by F.Mohamed Abdullah
