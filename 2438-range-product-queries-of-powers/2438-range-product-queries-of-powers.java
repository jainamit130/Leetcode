class Solution {
    public int[] productQueries(int n, int[][] queries) {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        int mod = (int)1e9+7;
        int pow = 0;
        while(n>0) {
            if((n&1)==1) list.add((list.getLast()*(1<<pow))%mod);
            pow++;
            n=n>>1;
        }
        int len = queries.length;
        int[] ans = new int[len];
        for(int i=0;i<len;i++) {            
            ans[i]=list.get(queries[i][1]+1)/list.get(queries[i][0]);
        }
        return ans;
    }
}