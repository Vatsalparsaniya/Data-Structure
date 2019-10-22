public class MinHeap {
    private int[] nodes;
    private int size;
    // array starts at 1 because parent index of 2 is 1 and normal division will not give me 0
    private static int population = 0;
    private static boolean full = false;

    public MinHeap(int size) {
        this.size = size + 1;
        nodes = new int[size + 1];
        //for a comparison later - you don't need the 0th element
        nodes[0] = Integer.MIN_VALUE;
    }

    public int getLeftChildIndex(int parentIndex) {
        return parentIndex *2;
    }

    public int getRightChildIndex(int parentIndex) {
        return parentIndex * 2 + 1;
    }

    // hopefully it will be floored
    public int getParentIndex(int childIndex) {
        return childIndex / 2;
    }

    public void printNodes() {
        for(int i = 1; i < size; i++) {
            System.err.print(nodes[i]);
            System.err.print(" ");
        }
    }

    public void swap(int index1, int index2) {
        nodes[index1] = nodes[index1] + nodes[index2];
        nodes[index2] = nodes[index1] - nodes[index2];
        nodes[index1] = nodes[index1] - nodes[index2];
    }

    public boolean isLeaf(int index) {
        if (index >= size / 2 && index <= size) {
            return true;
        } else {
            return false;
        }
    }

    //    public void heapifyDown(int parentIndex) {
//        boolean handled = false;
//        if (getLeftChildIndex(parentIndex) < size) {
//            handled = true;
//            if (nodes[getLeftChildIndex(parentIndex)] < nodes[parentIndex]) {
//                swap(getLeftChildIndex(parentIndex), parentIndex);
//                heapifyDown(getLeftChildIndex(parentIndex));
//            }
//        }
//    }
    public void heapifyDown(int currentIndex) {
        if (!isLeaf(currentIndex)) {
            if (nodes[currentIndex] > nodes[getLeftChildIndex(currentIndex)] || nodes[currentIndex] > nodes[getRightChildIndex(currentIndex)]) {

                // try swapping with the SMALLER child and keep pushing it down
                if (nodes[getLeftChildIndex(currentIndex)] < nodes[getRightChildIndex(currentIndex)]) {
                    swap(currentIndex, getLeftChildIndex(currentIndex));
                    heapifyDown(getLeftChildIndex(currentIndex));
                } else {
                    swap(currentIndex, getRightChildIndex(currentIndex));
                    heapifyDown(getRightChildIndex(currentIndex));
                }
            }
        }
    }

    public void insertToMinHeap(int value) {
        if (!full) {
            // filling up the heap first
            if (population < size - 1) {
                population += 1;
                nodes[population] = value;
            } else {
                full = true;
            }

            int current = population;
            while(nodes[current] < nodes[getParentIndex(current)]) {
                swap(current, getParentIndex(current));
                current = getParentIndex(current);
            }
        } else {
            if (value > nodes[1]) {
                nodes[1] = value;
                heapifyDown(1);
            }
        }


    }

    public static void main(String[] args) {

        MinHeap minHeap = new MinHeap(9);
        int[] arr = {40, 60, 10, 20, 50 ,30};
        for(int i : arr) {
            minHeap.insertToMinHeap(i);
        }

//        minHeap.printNodes();

        minHeap.insertToMinHeap(100);
        minHeap.insertToMinHeap(200);
        minHeap.insertToMinHeap(300);
        minHeap.insertToMinHeap(301);
        minHeap.insertToMinHeap(302);
        minHeap.insertToMinHeap(304);
        minHeap.insertToMinHeap(303);
        minHeap.insertToMinHeap(333);

        minHeap.printNodes();
    }
}
