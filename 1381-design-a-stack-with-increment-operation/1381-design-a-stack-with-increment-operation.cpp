class CustomStack {
public:
    vector<int> nums;
    int size;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(nums.size()==size){
            return;
        }
        nums.push_back(x);
    }
    
    int pop() {
        if(nums.size()==0){
            return -1;
        }
        int ans = nums.back();
        nums.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min((int)nums.size(),k);i++){
            nums[i]+=val;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */