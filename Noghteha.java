import java.util.ArrayList;

class Noghteha {
    private ArrayList<Noghte> noghteha;
    private Noghte firstNoghte;
    private boolean first = true;
    private int n;

    Noghteha(int n) {
        noghteha = new ArrayList<>(n);
        this.n = n;
    }

    Noghte getFirstNoghte() {
        return firstNoghte;
    }

    private void setFirstNoghte(Noghte firstNoghte) {
        this.firstNoghte = firstNoghte;
    }

    void add(Noghte newNoghte) {
        noghteha.add(newNoghte);
        if (first) {
            setFirstNoghte(newNoghte);
            first = false;
        }
    }

    void remove(Noghte p) {
        noghteha.remove(p);
    }

    boolean isEmpty() {
        return noghteha.isEmpty();
    }

    ArrayList<Noghte> getNoghteha() {
        return noghteha;
    }

    int totalN() {
        return n;
    }
}
