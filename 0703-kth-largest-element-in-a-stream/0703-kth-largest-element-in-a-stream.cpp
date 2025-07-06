class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        int i=0;
        size=k;
        while(i<nums.size()){
            if(pq.size()<size){
                pq.push(nums[i]);
            } else {
                if(pq.top()<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            i++;
        }
    }
    
    int add(int val) {
        if(pq.size()<size){
            pq.push(val);
        } else {
            if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);


3, [4 , 5 , 8 , 2]

2   4   5   8

8   5   4   2

8   5   4   3   2


 */