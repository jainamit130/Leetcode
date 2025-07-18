class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int N = nums.size();
        int n = nums.size()/3;
        vector<long long> firstHalf(n+1,LLONG_MIN);
        int firstIndex = 0,secondIndex = n;
        vector<long long> secondHalf(n+1,LLONG_MIN);
        long long firstHalfSum = 0, secondHalfSum = 0, ans = LLONG_MAX;
        for(int i=0;i<N;i++) {
            int j = N-i-1;
            firstHalfSum+=nums[i];
            maxHeap.push(nums[i]);
            secondHalfSum+=nums[j];
            minHeap.push(nums[j]);
            if(maxHeap.size()>n) {
                firstHalfSum-=maxHeap.top();
                maxHeap.pop();
            }
            if(minHeap.size()>n) {
                secondHalfSum-=minHeap.top();
                minHeap.pop();
            }
            if(maxHeap.size()==n && firstIndex<=n && i>=n-1) firstHalf[firstIndex++]=firstHalfSum;
            if(minHeap.size()==n && secondIndex>=0 && j<=N-n) secondHalf[secondIndex--]=secondHalfSum;
        }

        for(int i=0;i<=n;i++) {
            if(firstHalf[i]!=LLONG_MIN && secondHalf[i]!=LLONG_MIN) ans = min(ans,firstHalf[i]-secondHalf[i]);
        }
        return ans;
    }
};


/*

0   1   2   3   4   5
7   9   5   8   1   3


-1  -1  16  12  12  6   4
17  17  13  11  4   -1  -1

pq => max n with sum


3   1   2




*/