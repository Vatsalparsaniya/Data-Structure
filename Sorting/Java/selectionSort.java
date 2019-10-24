class Sorting{
    public static void sort(int arr[]){
        int n = arr.length;
        for(int i = 0; i < n-1; i++){
            int min_idx = i;
            for(int j = i+1; j<n; j++){
                if(arr[j] < arr[min_idx] ){
                    min_idx = j;
                }
            }
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;

        }
    }
    public static void printArray(int arr[]){
        int n = arr.length;
        for(int i = 0; i < n; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String args[])  {
        int arr[] = {6,1,3,5,2,4};
        System.out.println("Array before sorting: ");
        printArray(arr);
        sort(arr); 
        System.out.println("\nArray after sorting: ");
        printArray(arr);
    }
}