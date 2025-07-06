class Trie {
    private Trie[] children;
    public Trie() {
        children = new Trie[2];
    }

    public void addNumber(int num) {
        Trie ptr = this;
        for(int i=31;i>=0;i--) {
            int bit = (num>>i)&1;
            if(ptr.children[bit]==null) {
                ptr.children[bit] = new Trie();
            }
            ptr=ptr.children[bit];
        }
        return;
    }

    public int query(int num) {
        Trie ptr = this;
        int ans = 0;
        for(int i=31;i>=0;i--) {
            int bit = ((num>>i)&1);
            int oppositeBit = 1-bit;
            if(ptr.children[oppositeBit]!=null) {
                ans = ans | (1<<i);
                ptr=ptr.children[oppositeBit];
            } else {
                ptr=ptr.children[bit];
            }
        }
        return ans;
    }
}

class Solution {
    public int findMaximumXOR(int[] nums) {
        Trie root = new Trie();
        for (int num : nums) {
            root.addNumber(num);
        }
        int ans = 0;
        for (int num : nums) {
            ans = Math.max(ans,root.query(num));
        }
        return ans;
    }
}