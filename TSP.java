import java.util.ArrayList;

class TSP {
    private boolean type;

    TSP(boolean type) {
        this.type = type;
    }

    long find(Noghteha noghteha) {
        long runtime = System.nanoTime();
        if (!type)
            nearestNeighbor(noghteha);
        else
            optimalTSP(noghteha);
        runtime = System.nanoTime() - runtime;
        System.out.println("Runtime of algorithm: " + runtime + "ns");
        return runtime;
    }

    private double getDistance(Noghte a, Noghte b) {
        return Math.sqrt(Math.pow(a.getX() - b.getX(), 2) + Math.pow(a.getY() - b.getY(), 2));
    }

    private void nearestNeighbor(Noghteha noghteha) {
        Noghte currentNoghte = noghteha.getFirstNoghte();
        noghteha.remove(currentNoghte);

        while (!noghteha.isEmpty()) {
            double minDistance = Double.MAX_VALUE;
            Noghte minNoghte = null;
            for (Noghte pnt : noghteha.getNoghteha()) {
                double distance = getDistance(currentNoghte, pnt);
                //System.out.println("Distance between (" + currentNoghte.getX() + "," + currentNoghte.getY() + ") and (" + pnt.getX() + "," + pnt.getY() + ") is " + distance);
                if (distance < minDistance) {
                    minDistance = distance;
                    minNoghte = pnt;
                }
            }
            currentNoghte.setNextNoghte(minNoghte);
            //System.out.println("After (" + currentNoghte.getX() + "," + currentNoghte.getY() + ") comes (" + minNoghte.getX() + "," + minNoghte.getY() + ")");
            currentNoghte = minNoghte;
            noghteha.remove(currentNoghte);
        }
    }

    private int factorial(int n) {
        if (n == 1)
            return 1;
        else
            return n * factorial(n - 1);
    }

    private void optimalTSP(Noghteha noghteha) {
        double minDistance = Double.MAX_VALUE;  // Really extreme!
        ArrayList<Noghte> noghtehamun = noghteha.getNoghteha();
        int totalN = noghteha.totalN();
        int[] perm = new int[totalN - 1];
        int[] savedPerm = new int[totalN - 1];
        Permutation pr = new Permutation(totalN - 1);
        int fact = factorial(totalN - 1);

        for (int p = 0; p < fact; p++) {
            pr.nextPermutation(perm);
            double tempDistance = getDistance(noghtehamun.get(0), noghtehamun.get(perm[0]));
            for (int i = 1; i < totalN - 1; i++)  // Calculate current permutations distance based on perm[i]
                tempDistance += getDistance(noghtehamun.get(perm[i - 1]), noghtehamun.get(perm[i]));

            if (tempDistance < minDistance) {
                minDistance = tempDistance;
                System.arraycopy(perm, 0, savedPerm, 0, totalN - 1);
            }

            /*System.out.print("Permutation #" + p + ": 0 ");
            for (int i = 0; i < totalN - 1; i++) {
                System.out.print(perm[i] + " ");
            }
            System.out.println("had distance of: " + tempDistance);*/
        }

        System.out.print("Best permutation is: 0 ");
        for (int i = 0; i < totalN - 1; i++) {
            System.out.print(savedPerm[i] + " ");
        }
        System.out.println("with distance of: " + minDistance);

        // Build the linked-list of noghte
        noghtehamun.get(0).setNextNoghte(noghtehamun.get(savedPerm[0]));
        for (int i = 1; i < totalN - 1; i++) {
            noghtehamun.get(savedPerm[i - 1]).setNextNoghte(noghtehamun.get(savedPerm[i]));
        }
    }
}
