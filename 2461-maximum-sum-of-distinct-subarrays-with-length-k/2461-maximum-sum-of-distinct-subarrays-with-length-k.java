class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int i=0,j=0;
        Map<Integer, Integer> mp = new HashMap<>();
        long sum = 0;
        long ans = 0;
        while(j<nums.length) {
            while(i<j && mp.containsKey(nums[j])) {
                mp.put(nums[i],mp.get(nums[i])-1);
                sum-=nums[i];
                if(mp.get(nums[i])==0){
                    mp.remove(nums[i]);
                }
                i++;
            }

            mp.put(nums[j],mp.getOrDefault(nums[j],0)+1);
            sum+=nums[j];
            if(j-i+1==k){
                ans=Math.max(ans,sum);
                sum-=nums[i];
                mp.put(nums[i],mp.get(nums[i])-1);
                if(mp.get(nums[i])==0){
                    mp.remove(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
}