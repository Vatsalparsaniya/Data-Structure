class InsertionSort { 
    void insertionSort(int arr[]) {
        for (int i = 1; i < arr.length; ++i) {
            int key = arr[i]; 
            int j = i - 1; 
            while (j >= 0 && arr[j] > key){ 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 
  
    static void display(int arr[]) { 
        for (int i = 0; i < arr.length; ++i) 
            System.out.print(arr[i] + " "); 
  
        System.out.println(); 
    } 
  
    public static void main(String args[]) 
    { 
        int arr[] = { 22, 21, 23, 15, 18, 5, 8 }; 
        System.out.println("Array before sorting: ");
        display(arr);
        InsertionSort obj = new InsertionSort(); 
        obj.insertionSort(arr); 
        System.out.println("\nArray after sorting: ");
        display(arr); 
    } 
} 