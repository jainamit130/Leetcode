class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        int j=0;
        int n = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();
        int[] expandedIndex = new int[n];
        for(int i=0;i<n;i++) {
            while(j<n && mp.size()<=k) {
                mp.put(nums[j],mp.getOrDefault(nums[j],0)+1);
                if(mp.size()>k) {mp.remove(nums[j]);break;}
                j++;
            }
            expandedIndex[i]=j;
            mp.put(nums[i],mp.get(nums[i])-1);
            if(mp.get(nums[i])==0) mp.remove(nums[i]);
        }
        j=0;
        mp.clear();
        int ans = 0;
        for(int i=0;i<n;i++) {
            while(j<n && mp.size()<k) {
                mp.put(nums[j],mp.getOrDefault(nums[j],0)+1);
                j++;
            }
            if(mp.size()==k) ans += expandedIndex[i]-j+1;
            mp.put(nums[i],mp.get(nums[i])-1);
            if(mp.get(nums[i])==0) mp.remove(nums[i]);
        }
        return ans;
    }
}

/*

0   1   2   3   4   5   6   7
1   2   1   1   2   3   2   1
i

3 + 3 + 3 + 3 + 1 + 1 = 14 


*/