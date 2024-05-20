class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<bool> is_special(size - 1);
        
        for (int i = 0; i < size - 1; i++) {
            is_special[i] = (nums[i] % 2 != nums[i + 1] % 2);
        }
        
        vector<int> prefix_sum(size);
        for (int i = 0; i < size - 1; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + (is_special[i] ? 1 : 0);
        }
        vector<bool> results(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            int start = queries[j][0];
            int end = queries[j][1];
            if (end == start) {
                results[j] = true;
            } else {
                int total_special_pairs = prefix_sum[end] - prefix_sum[start];
                results[j] = (total_special_pairs == end - start);
            }
        }
        
        return results;
    }
};