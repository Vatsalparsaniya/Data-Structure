import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class TextReader {
    private File file;
    private Scanner sc;

    TextReader(String filename) {
        file = new File(filename);
    }

    int poll() throws FileNotFoundException {
        sc = new Scanner(file);
        int n = sc.nextInt();
        System.out.println("Total number of noghteha: " + n);
        return n;
    }

    Noghte next() {
        int x, y;
        x = sc.nextInt();
        y = sc.nextInt();
        //System.out.println("Noghte added: " + x + " " + y);
        return new Noghte(x, y);
    }
}
