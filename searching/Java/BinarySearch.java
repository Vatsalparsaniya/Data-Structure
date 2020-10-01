// this program searches the given key(number) in a given array(sorted/unsorted) using Binary Search

class BinarySearch{
    public static void main(String[] args){

        int[] arr = {4, 2, 6, 54, 7, 9, 1, 90};

        int searchKey = 9;

        sortArr(arr);

        System.out.println("\nSorted array:\n");
        for(int x=0; x<arr.length; x++){
            System.out.print(arr[x]+" ");
        }
        System.out.println("\n");


        int result = findsearchKey(arr, searchKey);
        if(result == -1){
            System.out.println(searchKey+" not found in array\n");
        }else{
            System.out.println(searchKey+" is found at index: "+result);
            System.out.println();
        }
    }

    static void sortArr(int[] arr) {        //sorting array using bubble sort

        int temp = 0;

        for (int x = 0; x < arr.length; x++) {
            for(int y=x+1; y<arr.length; y++){
                if(arr[x] > arr[y]){
                    temp = arr[x];
                    arr[x] = arr[y];
                    arr[y] = temp;
                }
            }

        }
    }

    static int findsearchKey(int[] arr, int key) {

        int l = 0;              //leftmost index of the array   (lowest index)
        int h = arr.length - 1;    //rightmost index of the array.   (highest index)

        while (l <= h) {

            int m = l + (h - l) / 2;    // middle index

            if (arr[m] == key)       // check whether the key is equal to the middle element's value
                return m;

            if (arr[m] < key) {       // if key is greater than middle element's value, ignore the left half
                l = m + 1;
            }

            else {               // if key is lower than the middle element's value, ignore the right half
                h = m - 1;
            }
        }
        return -1;

    }

}