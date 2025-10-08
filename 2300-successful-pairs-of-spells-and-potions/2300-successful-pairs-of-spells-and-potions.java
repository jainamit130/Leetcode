class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int[] ans = new int[spells.length];
        for(int i=0;i<spells.length;i++) {
            int start = 0;
            int end = potions.length-1;
            int index = -1;
            while(start<=end) {
                int mid = (start + end)/2;
                int val = (int)((success+(success%spells[i]==0?0:spells[i]))/(long)spells[i]);
                if(potions[mid]>=val) {
                    index = mid;
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }
            if(index!=-1) {
                ans[i] = potions.length-index;
            }
        }
        return ans;
    }
}