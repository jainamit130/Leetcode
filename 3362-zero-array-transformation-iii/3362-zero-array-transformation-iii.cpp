class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int m = nums.size();
        sort(queries.begin(),queries.end());
        priority_queue<pair<int,int>> pq;
        vector<int> prefix(m+1);
        int i=0;  // nums index
        int j=0; // queries index
        while(i<m) {
            if(i>0){
                prefix[i]+=prefix[i-1];
            }

            // Load the queries covering index i 
            while(j<n && queries[j][0]<=i && i<=queries[j][1]) {
                pq.push({queries[j][1],queries[j][0]});
                j++;
            }

            while(!pq.empty() && nums[i]+prefix[i]>0 && pq.top().first>=i) {
                auto [u,l]= pq.top();
                prefix[i]-=1;
                prefix[u+1]+=1;
                pq.pop();
            }
            
            if(prefix[i]+nums[i]>0){
                return -1;
            }

            i++;
        }

        return pq.size();
    }
};


/*

0   1   2   3   4   5   6
1   2   3   4   5   6   7
-1  0   0   0   0   0   +1

-1  -1  -1  -1  -1  -1  0


queries= [0,5],[0,2]


[[1,3],[0,2],[1,3],[1,2]]

0   2
1   3
1   3
1   2



1. Sort the queries
2. Iterate nums
3. for each nums index i => load all the queries which cover index i into priority queue (such that the upper bound is in descending order)
4. update the query on prefix array until either the pq is exhausted or the nums[i]+prefix[i]==0
5. if pq exhausted and still this is not true => nums[i]+prefix[i]==0 then return -1
6. at the end return pq.size();

*/