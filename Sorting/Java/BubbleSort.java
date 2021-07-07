class Sort{
    public static void bubbleSort(int arr[]){
        int n = arr.length;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j<n-1-i; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    public static void printArray(int arr[]){
        int n = arr.length;
        for(int i = 0; i<n; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String args[]) {
        int arr[] = {5,1,4,2,8};
        System.out.println("Array before sorting: ");
        printArray(arr);
        bubbleSort(arr); 
        System.out.println("\nArray after sorting: ");
        printArray(arr);
    }
}