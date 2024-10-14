class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto n:nums){
            pq.push(n);
        }
        long long score = 0;
        while(k){
            int n=pq.top();
            pq.pop();
            score+=(long long)n;
            n=ceil(n/(double)3);
            pq.push(n);
            k--;
        }
        return score;
    }
};