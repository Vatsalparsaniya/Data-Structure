import javax.swing.*;
import java.awt.*;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {
        try {

            TextReader tr = new TextReader("input.txt");  // specify the input address

            int n = tr.poll();
            Noghteha noghteha = new Noghteha(n);
            for (int i = 0; i < n; i++)
                noghteha.add(tr.next());

            boolean type = true;  // type=false for nearestNeighbor and type=true for optimalTSP
            TSP tsp = new TSP(type);
            long runtime = tsp.find(noghteha);
            runtime /= 1000;

            int scale = 6;
            Plotter pl = new Plotter(noghteha, scale);
            JFrame frame = new JFrame();
            frame.setSize(scale * 220, scale * 220 + 60);
            frame.setLayout(new BorderLayout());
            frame.setResizable(false);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            if (!type) {
                frame.setTitle("Nearest Neighbor (RunTime: " + runtime + "us)");
            } else {
                frame.setTitle("Optimal TSP (RunTime: " + runtime + "us)");
            }
            frame.setVisible(true);
            frame.setContentPane(pl);

        } catch (FileNotFoundException e) {
            System.err.println("There was a fatal problem with the input.");
            e.printStackTrace();
        }
    }
}
