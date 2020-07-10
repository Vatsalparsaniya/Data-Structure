class Noghte {
    private int x, y;
    private Noghte nextNoghte;
    private boolean nextNoghteAvailability = false;

    Noghte(int x, int y) {
        this.x = x;
        this.y = y;
        nextNoghte = null;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    Noghte getNextNoghte() {
        return nextNoghte;
    }

    void setNextNoghte(Noghte p) {
        nextNoghte = p;
        nextNoghteAvailability = true;
    }

    boolean hasNextNoghte() {
        return nextNoghteAvailability;
    }
}
