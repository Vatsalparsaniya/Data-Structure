class BubbleSort {
    public static void main(String[] args) {
    }

    static void bubble(int arr[], int i, int n) {
        boolean isSwapping = false;
        do {
            isSwapping = false;
            for (i = 0; i < arr.length-1; i++) {

                if (arr[i] > arr[i + 1]) {

                    int temp = arr[i];

                    arr[i] = arr[i + 1];

                    arr[i + 1] = temp;

                    isSwapping = true;
                }
            }
        } while (isSwapping);
    }
}
