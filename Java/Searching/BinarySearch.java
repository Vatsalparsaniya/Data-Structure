import java.util.ArrayList;
import java.util.List;

public class LIS {
    public static int lowerBound(List<Integer> a, int low, int high, int element){
        while(low < high){
            int middle = low + (high - low)/2;
            if(element > a.get(middle))
                low = middle + 1;
            else
                high = middle;
        }
        return low;
    }

    public static int upperBound(List<Integer> a, int low, int high, int element){
        while(low < high){
            int middle = low + (high - low)/2;
            if(a.get(middle) > element)
                high = middle;
            else
                low = middle + 1;
        }
        return low;
    }
}
