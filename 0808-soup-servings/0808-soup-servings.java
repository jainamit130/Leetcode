class Solution {
    Double[][][] cache;
    Map<Integer,List<Integer>> options = Map.of(
        0,List.of(-100,0),
        1,List.of(-75,-25),
        2,List.of(-50,-50),
        3,List.of(-25,-75)
    );

    public double soupServings(int n) {
        if (n >= 4800) return 1.0;
        n = (n + 24) / 25; // scale down
        cache = new Double[n+1][n+1][2];
        return solve(n, n, 0) + solve(n, n, 1);
    }

    public double solve(int a, int b, int type) {
        if (type == 1) {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0 || b <= 0) return 0;
        } else {
            if (a <= 0 && b > 0) return 1;
            if (b <= 0) return 0;
        }

        if (cache[a][b][type] != null) return cache[a][b][type];
        double prob = 0;
        for (List<Integer> op : options.values()) {
            int na = a + op.get(0) / 25;
            int nb = b + op.get(1) / 25;
            prob += 0.25 * solve(na, nb, type);
        }
        return cache[a][b][type] = prob;
    }
}
