class SegmentTree {
    private int[] st;

    public SegmentTree(int a[], int n) {
        int x = (int) Math.ceil(Math.log(n) / Math.log(2));
        int max_size = 2 * (int) Math.pow(2, x) - 1;
        st = new int[max_size];
        constructSTUtil(a, 0, n - 1, 0);
    }

    public int constructSTUtil(int a[], int s, int e, int index) {
        if (s == e) {
            st[index] = a[s];
            return a[s];
        }
        int mid = s + (e - s) / 2;
        st[index] = constructSTUtil(a, s, mid, 2 * index + 1) +
                constructSTUtil(a, mid + 1, e, 2 * index + 2);
        return st[index];
    }

    public int getSum(int n, int qs, int qe) {
        // Check for erroneous input values
        if (qs < 0 || qe > n - 1 || qs > qe) {
            System.out.println("Invalid Input");
            return -1;
        }
        return getSumUtil(0, n - 1, qs, qe, 0);
    }

    public int getSumUtil(int ss, int se, int qs, int qe, int si) {
        // If segment of this node is a part of given range, then return the sum of the segment
        if (qs <= ss && qe >= se)
            return st[si];

        // If segment of this node is outside the given range
        if (se < qs || ss > qe)
            return 0;

        // If a part of this segment overlaps with the given range
        int mid = ss + (se - ss) / 2;
        return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
                getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
    }

    public void updateValue(int arr[], int n, int i, int new_val) {
        // Check for erroneous input index
        if (i < 0 || i > n - 1) {
            System.out.println("Invalid Input");
            return;
        }

        // Get the difference between new value and old value
        int diff = new_val - arr[i];

        // Update the value in array
        arr[i] = new_val;

        // Update the values of nodes in segment tree
        updateValueUtil(0, n - 1, i, diff, 0);
    }

    public void updateValueUtil(int ss, int se, int i, int diff, int si) {
        // Base Case: If the input index lies outside the range of this segment
        if (i < ss || i > se)
            return;

        // If the input index is in range of this node, then update the
        // value of the node and its children
        st[si] += diff;
        if (se != ss) {
            int mid = ss + (se - ss) / 2;
            updateValueUtil(ss, mid, i, diff, 2 * si + 1);
            updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
        }
    }

    public static void main(String args[]) {
        int arr[] = {1, 3, 5, 7, 9, 11};
        int n = arr.length;
        SegmentTree tree = new SegmentTree(arr, n);

        // Print sum of values in array from index 1 to 3
        System.out.println("Sum of values in given range[1,3] = " + tree.getSum(n, 1, 3));

        // Update: set arr[1] = 10 and update corresponding segment tree nodes
        tree.updateValue(arr, n, 1, 10);

        // Find sum after the value is updated
        System.out.println("Sum of values in given range[1,3] = " + tree.getSum(n, 1, 3));
    }
}