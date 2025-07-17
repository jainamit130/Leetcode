class Solution {
    public int findPairs(int[] nums, int k) {
        Arrays.sort(nums);
        Set<Integer> st= new HashSet();
        int ans = 0;
        int i = 0;
        while(i<nums.length) {
            int flag = 0;
            while(i+1<nums.length && nums[i]==nums[i+1]) {
                if(k==0 && flag==0) {
                    flag = 1;
                    ans++;
                }
                i++; 
            }
            int val1 = nums[i]-k;
            int val2 = nums[i]+k;
            if(st.contains(val1) || st.contains(val2)) ans++;
            st.add(nums[i]);
            i++;
        }
        return ans;
    }
}



/*

1   1   3   4   5



*/