class Solution {
    HashMap<String,Long> memo = new HashMap<>();
    public long helper(int i,int nums[],int s,int e){
         if(i==nums.length){
            return 1;
        }
        String key = s+"-"+e+"-"+i;
        if(memo.containsKey(key)){
            return memo.get(key);
        }
        long ans = 0;
        int j= s;
        int k = Math.min(e,nums[i]);
        while(j<=nums[i] && k>=0){
            int sum = j+k;
            if(sum==nums[i]){
                ans = (ans + helper(i+1,nums,j,k))%1000000007;
                j++;
                k--;
            } else if(sum<nums[i]){
                j++;
            }else {
                k--;
            }
        }
        memo.put(key,ans);
        return ans;
    }
    public int countOfPairs(int[] nums) {
        long ans = helper(0,nums,0,50);
        return (int)ans;
    }
}