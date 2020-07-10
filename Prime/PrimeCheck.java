import java.util.Scanner;

public class PrimeCheck {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int a_i = 0; a_i < n; a_i++) {
            a[a_i] = in.nextInt();
        }
        in.close();

        for (int anA : a) {
            if (isPrime(anA)) {
                System.out.println("Prime");
            } else {
                System.out.println("Not prime");
            }
        }
    }


    private static boolean isPrime(int n) {
        if (n == 2) { // 2 always prime
            return true;
        }
        if (n == 1 || n % 2 == 0) { // 1 and even always not prime
            return false;
        }
        // start checking with 3 since 1 and 2 are covered above

        for (int i = 3; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
