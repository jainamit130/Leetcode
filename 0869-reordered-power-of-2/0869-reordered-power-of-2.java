class Solution {
    Map<Integer, Integer> mp = new HashMap<>();

    public boolean reorderedPowerOf2(int n) {
        if(n==1) return true;
        int num = n;
        while (n > 0) {
            mp.put(n % 10, mp.getOrDefault(n % 10, 0) + 1);
            n /= 10;
        }
        return solve(num);
    }

    boolean solve(int num) {
        if (mp.isEmpty()) {
            return isValid(num);
        }
        int start = num==0 ? 1 : 0;
        boolean ans = false;
        for(int i=start;i<=9;i++) {
            if((mp.getOrDefault(i,0))>0) {
                mp.put(i,mp.get(i)-1);
                if(mp.get(i)==0) mp.remove(i);
                ans = ans || solve(num*10+i);
                mp.put(i,mp.getOrDefault(i,0)+1);
            }
        }
        return ans;
    }

    boolean isValid(int num) {
        num--;
        if (num < 0) return false;
        boolean flag = true;
        while (num > 0) {
            if ((num & 1) == 0) {
                flag = false;
                break;
            }
            num = num >> 1;
        }
        return flag;
    }
}

/*

2   5   6

*/