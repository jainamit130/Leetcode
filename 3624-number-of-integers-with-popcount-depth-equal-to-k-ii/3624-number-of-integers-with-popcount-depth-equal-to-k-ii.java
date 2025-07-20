class SegTree {
    public int leftIndex;
    public int rightIndex;
    public SegTree left;
    public SegTree right;
    public int[] count;

    public SegTree(int leftIdx,int rightIdx) {
        leftIndex = leftIdx;
        rightIndex = rightIdx;
        count = new int[6];
    }
    
    public SegTree(int leftIdx,int rightIdx,int depth) {
        leftIndex = leftIdx;
        rightIndex = rightIdx;
        count = new int[6];
        if(depth!=-1 && depth<=5) count[depth]=1;
    }

    public void update(int index,int newDepth,int oldDepth) {
        if(leftIndex==index && leftIndex==rightIndex) {
            if(oldDepth!=-1) count[oldDepth]=0;
            if(newDepth<=5) count[newDepth]=1;
            return;
        }

        int mid = (leftIndex + rightIndex)/2;
        if(mid>=index) {
            if(left==null) left = new SegTree(leftIndex,mid,newDepth);
            left.update(index,newDepth,oldDepth);
        } else {
            if(right==null) right = new SegTree(mid+1,rightIndex,newDepth);
            right.update(index,newDepth,oldDepth);
        }

        for(int i=0;i<=5;i++) {
            count[i]=0;
            if(left!=null) count[i] += left.count[i];
            if(right!=null) count[i] += right.count[i];
        }
        return;
    }

    public int query(int leftIdx,int rightIdx,int depthReq) {
        if(leftIndex>rightIdx || rightIndex<leftIdx) return 0;
        if(leftIndex>=leftIdx && rightIndex<=rightIdx) return count[depthReq];
        int leftSum = (left != null) ? left.query(leftIdx, rightIdx, depthReq) : 0;
        int rightSum = (right != null) ? right.query(leftIdx, rightIdx, depthReq) : 0;
        return leftSum + rightSum;
    }
};

class Solution {
    public int getSetBits(long n) {
        int setBits = 0;
        while(n>0) {
            setBits = setBits + (((n&1)==1) ? 1 : 0);
            n = n>>1;
        }
        return setBits;
    }
    
    public int[] popcountDepth(long[] nums, long[][] queries) {
        int[] depths = new int[52];
        for(int i=2;i<52;i++) {
            depths[i] = depths[getSetBits(i)] + 1;
        }
        SegTree root = new SegTree(0,nums.length-1);
        for(int i=0;i<nums.length;i++) {
            int depth = nums[i]==1 ? 0 : depths[getSetBits(nums[i])]+1;
            root.update(i,depth,-1);
        }

        List<Integer> ans = new ArrayList();
        for(int i=0;i<queries.length;i++) {
            int type = (int)queries[i][0];
            if(type==1) {
                ans.add(root.query((int)queries[i][1],(int)queries[i][2],(int)queries[i][3]));
            }  else {
                int idx = (int)queries[i][1];
                long val = queries[i][2];
                int oldDepth = nums[idx]==1 ? 0 : depths[getSetBits(nums[idx])] + 1;
                int newDepth = val==1 ? 0 : depths[getSetBits(val)] + 1;
                root.update(idx, newDepth, oldDepth);
                nums[idx] = val;
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}