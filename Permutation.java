class Permutation {
    private final static boolean LEFT_TO_RIGHT = true;
    private final static boolean RIGHT_TO_LEFT = false;
    private int n;
    private int[] a;
    private boolean isFirst;
    private boolean[] dir;

    Permutation(int n) {
        this.n = n;
        a = new int[n];
        dir = new boolean[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
            dir[i] = RIGHT_TO_LEFT;  // initially all directions are set to RIGHT TO LEFT i.e. 0.
        }
        isFirst = true;
    }

    private static int searchArr(int a[], int n, int mobile) {
        for (int i = 0; i < n; i++)

            if (a[i] == mobile)
                return i + 1;

        return 0;
    }  // Utility functions for finding the position of largest mobile integer in a[].

    private static int getMobile(int a[], boolean dir[], int n) {
        int mobile_prev = 0, mobile = 0;

        for (int i = 0; i < n; i++) {
            // direction 0 represents
            // RIGHT TO LEFT.
            if (dir[a[i] - 1] == RIGHT_TO_LEFT &&
                    i != 0) {
                if (a[i] > a[i - 1] &&
                        a[i] > mobile_prev) {
                    mobile = a[i];
                    mobile_prev = mobile;
                }
            }

            // direction 1 represents
            // LEFT TO RIGHT.
            if ((dir[a[i] - 1] == LEFT_TO_RIGHT) && (i != n - 1)) {
                if (a[i] > a[i + 1] &&
                        a[i] > mobile_prev) {
                    mobile = a[i];
                    mobile_prev = mobile;
                }
            }
        }

        if (mobile == 0 && mobile_prev == 0)
            return 0;
        else
            return mobile;
    }  // To carry out step 1 of the algorithm i.e. to find the largest mobile integer.

    private static void changeToNextPermutation(int[] a, boolean[] dir, int n) {
        int mobile = getMobile(a, dir, n);
        int pos = searchArr(a, n, mobile);

        // swapping the elements
        // according to the
        // direction i.e. dir[].
        if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT) {
            int temp = a[pos - 1];
            a[pos - 1] = a[pos - 2];
            a[pos - 2] = temp;
        } else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT) {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;
        }

        // changing the directions
        // for elements greater
        // than largest mobile integer.
        for (int i = 0; i < n; i++) {
            if (a[i] > mobile) {
                if (dir[a[i] - 1] == LEFT_TO_RIGHT)
                    dir[a[i] - 1] = RIGHT_TO_LEFT;

                else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
                    dir[a[i] - 1] = LEFT_TO_RIGHT;
            }
        }
    }  // Prints a single permutation

    void nextPermutation(int[] perm) {
        if (isFirst)
            isFirst = false;
        else
            changeToNextPermutation(a, dir, n);

        System.arraycopy(a, 0, perm, 0, n);
    }
}
