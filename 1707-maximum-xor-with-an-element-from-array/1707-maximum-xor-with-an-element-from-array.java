class Trie {
    Trie[] children = new Trie[2];
    public Trie() {}
    public void addNumToTrie(int num,int power) {
        Trie ptr = this;
        while(power>=0) {
            int val = (num>>power)&1;
            power--;
            if(ptr.children[val]==null) ptr.children[val]=new Trie();
            ptr = ptr.children[val];
        }
    }

    public int getMaxElement(int num,int power) {
        if(this==null) return 0;
        int currVal = 0;
        int ans = 0;
        Trie ptr = this;
        while(ptr!=null && power>=0) {
            int val = ((num >> power) & 1) ^ 1;
            if(ptr.children[val]!=null) {
                ptr = ptr.children[val];
                ans = ans|(1<<power);
            } else if(ptr.children[val ^ 1]!=null) {
                ptr = ptr.children[val ^ 1];
            } else return -1;
            power--;
        }
        return ans;
    }
};

class Solution {
    public int[] maximizeXor(int[] nums, int[][] queries) {
        int n = nums.length;
        int q = queries.length;
        Integer[] indexes = new Integer[q];
        int maxPower = 31;
        Trie root = new Trie();
        for(int i=0;i<q;i++) indexes[i]=i;
        Arrays.sort(nums);
        Arrays.sort(indexes,(lhs,rhs)->{
            return Integer.compare(queries[lhs][1],queries[rhs][1]);
        });
        int[] ans = new int[q];
        int index = 0; 
        for(int i=0;i<q;i++) {
            int qIndex = indexes[i];
            while(index<n && nums[index]<=queries[qIndex][1]) {
                root.addNumToTrie(nums[index],maxPower);
                index++;
            }
            ans[qIndex] = root.getMaxElement(queries[qIndex][0],maxPower);
        }
        return ans;
    }
}


/*

0   1   2   3   4

3   1
1   3
5   6




*/ 