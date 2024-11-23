class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
      priority_queue<pair<int,int>> pq;
      int n = queries.size();
      sort(queries.begin(), queries.end());
      vector<int> v(nums.size() + 1, 0);
      int i = 0, k = 0;
      while (k < nums.size()) {
        if (k > 0)
          v[k] += v[k - 1];
        while (i < n && queries[i][0] <= k)
            pq.push({queries[i][1], queries[i][0]}), i++;
        while (k < nums.size() && !pq.empty() && nums[k] + v[k] > 0 && pq.top().first >= k) {
          v[k] -= 1;
          v[pq.top().first + 1] += 1;
          pq.pop();
        }
        if (nums[k] + v[k] > 0)
          return -1;
        
        k++;
      }

      return pq.size();
    }
};