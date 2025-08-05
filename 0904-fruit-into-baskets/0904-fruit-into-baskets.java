class Solution {
    public int totalFruit(int[] fruits) {
        int i=0,j=0;
        Map<Integer,Integer> mp = new HashMap<>();
        int count = 0;
        int ans = 0;
        int n = fruits.length;
        while(j<n) {
            mp.put(fruits[j],mp.getOrDefault(fruits[j],0)+1);
            count++;
            j++;

            while(i<j && mp.size()>2) {
                mp.put(fruits[i],mp.getOrDefault(fruits[i],0)-1);
                count--;
                if(mp.get(fruits[i])==0) mp.remove(fruits[i]);
                i++;
            }

            if(mp.size()<=2) ans = Math.max(ans,count);
        }
        return ans;
    }
}