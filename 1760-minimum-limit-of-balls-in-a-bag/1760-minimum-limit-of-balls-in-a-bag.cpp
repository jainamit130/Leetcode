class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1;  
        // O(log maxElement)
        int end = *max_element(nums.begin(),nums.end());
        int ans = end;
        // O(n log n)
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(isValid(nums,mid,maxOperations)) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }

    // O(n log n)
    bool isValid(vector<int>& nums,int penalty,int maxOperations) {
        priority_queue<int> pq;
        // O(n log n)
        for(auto n:nums) {
            pq.push(n);
        }
        // O(m log n)
        while(!pq.empty() && pq.top()>penalty && maxOperations>=0) {
            int currPenalty = pq.top();
            pq.pop();
            maxOperations-=ceil(currPenalty/(double)penalty)-1;
        }
        return maxOperations>=0;
    }
};

/*

9 -> 2  7
7 -> 2  5
5 -> 2  3

What are the constraints?
nums = [0,0,0]

Binary Search on the ans
Range:
1 to max(nums)

get mid = start+(end-start)/2;

check if we can achieve a ans of mid

x -> mid x-mid
x-mid -> mid x-2*mid


*/