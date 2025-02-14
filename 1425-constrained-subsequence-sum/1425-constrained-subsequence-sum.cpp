class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<vector<int>> pq;
        pq.push({0,-1});
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            while(i-pq.top()[1]>k) {
                pq.pop();
            }
            int topLastK = pq.top()[0];
            ans = max(ans,max({nums[i],nums[i]+topLastK}));
            pq.push({max({0,nums[i],nums[i]+topLastK}),i});
        }
        return ans;
    }
};

/*

10  2   -10  5  20


10  12   2   

pq: 10,0 

Clarifications

k will always be within the range of nums.size()? yes
nums can it be empty? no
can nums contain 0 and negative elements? yes
subsequence definition? 
can j be == i? no j<i
what constraints are we talking about? nums size = 10^5 and values of nums -1e4 to 1e4


nums k
j-i<=k 


Example

10  -11  -20  -5  20


10  2   -10  5  20


if sum becomes negative or 0 => start entirely next window => j++; i=j;
if sum stays positive then the 

dp[i][k] = tells starting from i whats the max sum subsequence that i can form ending at i+k




*/