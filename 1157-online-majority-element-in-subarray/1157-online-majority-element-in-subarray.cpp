class MajorityChecker {
public:
    vector<int> nums;
    MajorityChecker(vector<int>& arr) {
        nums=arr;
    }
    
    int query(int left, int right,int threshold) {
        int count = 1;
        int val = nums[left];
        for(int i=left+1;i<=right;i++) {
            if(nums[i]==val){
                count++;
            } else {
                count--;
                if(count<0){
                    val = nums[i];
                    count = 1;
                }
            }
        }

        if(threshold<=((right-left)/2)+count){
            return val;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */