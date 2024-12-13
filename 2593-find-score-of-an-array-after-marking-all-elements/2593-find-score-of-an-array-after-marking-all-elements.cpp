class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        vector<int> visited(n);
        while (!pq.empty()) {
            int value = pq.top()[0];
            int index = pq.top()[1];
            pq.pop();
            if (visited[index] == 0) {
                visited[index] = 1;
                score += value;
                if (index + 1 < n) {
                    visited[index + 1] = 1;
                }
                if (index - 1 >= 0) {
                    visited[index - 1] = 1;
                }
            }
        }
        return score;
    }
};