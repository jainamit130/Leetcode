class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int size = nums.size();
        map<int, vector<int>> difference_map;
        vector<int> transformations;
        
        computeDifferences(nums, k, difference_map, transformations, size);
        return calculateMinOperations(difference_map, transformations, size);
    }

private:
    void computeDifferences(vector<int>& array, int max_val, map<int, vector<int>>& difference_map, vector<int>& transformations, int size) {
        for (int i = 0; i < size / 2; ++i) {
            int val1 = array[i];
            int val2 = array[size - i - 1];
            int diff = abs(val1 - val2);
            int max_transform = max({val1, val2, max_val - val1, max_val - val2});
            difference_map[diff].push_back(max_transform);
            transformations.push_back(max_transform);
        }
        sort(transformations.begin(), transformations.end());
    }

    int calculateMinOperations(const map<int, vector<int>>& difference_map, const vector<int>& transformations, int size) {
        int min_operations = size; // Start with the maximum possible number of changes
        
        for (const auto& entry : difference_map) {
            int current_diff = entry.first;
            const vector<int>& transform_values = entry.second;
            
            int operations = initialOperations(transformations, current_diff, size);
            adjustOperations(transform_values, current_diff, operations);
            
            min_operations = min(min_operations, operations);
        }
        
        return min_operations;
    }
    
    int initialOperations(const vector<int>& transformations, int current_diff, int size) {
        int position = lower_bound(transformations.begin(), transformations.end(), current_diff) - transformations.begin();
        return position * 2 + ((size / 2) - position);
    }
    
    void adjustOperations(const vector<int>& transform_values, int current_diff, int& operations) {
        for (int transform : transform_values) {
            if (transform < current_diff) {
                operations -= 2;
            } else {
                operations -= 1;
            }
        }
    }
};
