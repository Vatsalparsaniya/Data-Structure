import javax.swing.*;
import java.awt.*;

class Plotter extends JPanel {
    private Noghteha noghteha;
    private int scale;

    Plotter(Noghteha noghteha, int scale) {
        this.noghteha = noghteha;
        this.scale = scale;
    }

    @Override
    protected void paintComponent(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setStroke(new BasicStroke(scale));
        g2d.setFont(new Font(g2d.getFont().getFontName(), Font.PLAIN, g2d.getFont().getSize() * (int) (scale / 1.5)));
        drawCoordinates(g2d);
        drawNoghteha(g2d);
        drawLines(g2d);
        drawNumbers(g2d);
    }

    private int newY(int y) {
        return scale * (10 + 100 - y);
    }

    private int newX(int x) {
        return scale * (10 + 100 + x);
    }

    private void drawCoordinates(Graphics2D g) {
        g.setColor(Color.BLACK);
        g.drawLine(newX(-100), newY(0), newX(100), newY(0));  // Reality Xs (y=0)
        g.drawString("X", newX(100), newY(0));
        g.drawLine(newX(0), newY(-100), newX(0), newY(100));  // Reality Ys (x=0)
        g.drawString("Y", newX(0), newY(100));
    }

    private void drawNoghteha(Graphics2D g) {
        g.setColor(Color.ORANGE);
        Noghte currentNoghte = noghteha.getFirstNoghte();
        while (currentNoghte != null) {
            g.drawOval(newX(currentNoghte.getX()) - 2 * scale, newY(currentNoghte.getY()) - 2 * scale, 4 * scale, 4 * scale);
            currentNoghte = currentNoghte.getNextNoghte();
        }
    }

    private void drawLines(Graphics2D g) {
        g.setColor(Color.BLUE);
        Noghte currentNoghte = noghteha.getFirstNoghte();
        while (currentNoghte.hasNextNoghte()) {
            g.drawLine(newX(currentNoghte.getX()), newY(currentNoghte.getY()), newX(currentNoghte.getNextNoghte().getX()), newY(currentNoghte.getNextNoghte().getY()));
            currentNoghte = currentNoghte.getNextNoghte();
        }
        g.setColor(Color.CYAN);
        g.drawLine(newX(currentNoghte.getX()), newY(currentNoghte.getY()), newX(noghteha.getFirstNoghte().getX()), newY(noghteha.getFirstNoghte().getY()));
    }

    private void drawNumbers(Graphics2D g) {
        Color darkOrange = new Color(100, 70, 20, 90);
        g.setColor(darkOrange);
        Noghte currentNoghte = noghteha.getFirstNoghte();
        int no = 1;
        while (currentNoghte != null) {
            g.drawString(Integer.toString(no++), newX(currentNoghte.getX()), newY(currentNoghte.getY()));
            currentNoghte = currentNoghte.getNextNoghte();
        }
    }
}
