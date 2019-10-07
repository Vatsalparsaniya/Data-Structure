package algorithms;
import java.util.*;

public class InsertionSort {
    private ArrayList<Integer> arr;

    public InsertionSort(ArrayList<Integer> arr) {
        this.arr = arr;
    }

    public ArrayList sort() {
        for (int i = 1; i < arr.size(); i++) {
            int key = arr.get(i);
            int sorted_index = i - 1;

//            move sorted numbers to the right of key if key is smaller
            while (sorted_index >= 0 && arr.get(sorted_index) > key) {
                arr.set(sorted_index + 1, arr.get(sorted_index));
                sorted_index -= 1;
            }
            arr.set(sorted_index + 1, key);
        }

        return arr;
    }
}
