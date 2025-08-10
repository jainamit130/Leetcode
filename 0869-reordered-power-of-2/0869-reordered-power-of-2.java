class Solution {
    Map<Integer, Integer> mp = new HashMap<>();
    int len; // To store length of original number

    public boolean reorderedPowerOf2(int n) {
        if (n == 1) return true;
        
        len = String.valueOf(n).length();
        
        while (n > 0) {
            mp.put(n % 10, mp.getOrDefault(n % 10, 0) + 1);
            n /= 10;
        }

        return solve(0); 
    }

    boolean solve(int num) {
        if (String.valueOf(num).length() == len && isValid(num)) {
            return true;
        }

        for (int i = (num == 0 ? 1 : 0); i <= 9; i++) {
            if (mp.getOrDefault(i, 0) > 0) {
                mp.put(i, mp.get(i) - 1);
                if (mp.get(i) == 0) mp.remove(i);

                if (solve(num * 10 + i)) return true;

                mp.put(i, mp.getOrDefault(i, 0) + 1);
            }
        }

        return false;
    }

    boolean isValid(int num) {
        return (num & (num - 1)) == 0;
    }
}


/*

2   5   6

*/