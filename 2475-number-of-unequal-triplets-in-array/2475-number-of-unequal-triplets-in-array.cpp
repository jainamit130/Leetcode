class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int k = 3;
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        vector<pair<int, int>> unique;  // (value, count)
        for (auto& [val, count] : freq)
            unique.emplace_back(val, count);

        int u = unique.size();
        vector<vector<int>> memo(u + 1, vector<int>(k + 1, -1));
        return dfs(0, 0, unique, k, memo);
    }

    int dfs(int index, int size, vector<pair<int, int>>& unique, int k, vector<vector<int>>& memo) {
        if (size == k) return 1;
        if (index == unique.size()) return 0;
        if (memo[index][size] != -1) return memo[index][size];

        // Option 1: skip current value
        int total = dfs(index + 1, size, unique, k, memo);

        // Option 2: pick current value (only if size < k)
        if (size < k) {
            int count = unique[index].second;
            total += count * dfs(index + 1, size + 1, unique, k, memo);
        }

        return memo[index][size] = total;
    }
};



// class Solution {
// public:
//     int unequalTriplets(vector<int>& nums) {
//         return unequalTuples(nums, 4); // Change 4 to 3 if testing triplets
//     }

//     int unequalTuples(vector<int>& nums, int k) {
//         vector<int> counts(1001, 0);          // Count of each number
//         vector<int> validGroup(k + 1, 0);         // tuples[i] = # of valid tuples of size i
//         validGroup[0] = 1;

//         int step = 1;
//         for (int num : nums) {
//             cout << "Step " << step++ << ", num = " << num << "\n";

//             vector<int> validGroupWithoutNum(k, 0);
//             validGroupWithoutNum[0] = 1;

//             for (int i = 1; i < k; ++i) {
//                 validGroupWithoutNum[i] = validGroup[i] - validGroupWithoutNum[i - 1] * counts[num];
//             }

//             // Print tuplesWithoutA
//             cout << "  validGroupWithoutNum: ";
//             for (int i = 0; i < k; i++) cout << validGroupWithoutNum[i] << " ";
//             cout << "\n";

//             // Update tuples
//             for (int i = k; i > 0; --i) {
//                 validGroup[i] += validGroupWithoutNum[i - 1];
//             }

//             // Print current tuples
//             cout << "  Updated group: ";
//             for (int i = 0; i <= k; i++) cout << validGroup[i] << " ";
//             cout << "\n";

//             counts[num]++;
//             // Print counts
//             cout << "  Updated counts[" << num << "] = " << counts[num] << "\n\n";
//         }

//         cout << "Final tuples array: ";
//         for (int i = 0; i <= k; i++) cout << validGroup[i] << " ";
//         cout << "\n";

//         return validGroup[k];
//     }
// };

// class Solution {
// public:
//     int unequalTriplets(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(auto n:nums) mp[n]++;
//         int left = 0, right = nums.size();
//         int ans = 0;
//         for(auto [num,freq]:mp) {
//             right-=freq;
//             ans += left*freq*right;
//             left+=freq;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int unequalTriplets(vector<int>& nums) {
//         unordered_map<int,int> postMap;
//         unordered_map<int,int> preMap;
//         for(auto n:nums) {
//             postMap[n]++;
//         }
//         int n = nums.size();
//         int ans = 0;
//         for(int j=0;j<n;j++) {
//             postMap[nums[j]]--;
//             if(postMap[nums[j]]==0) postMap.erase(nums[j]);
//             int numberOfElementsAfter = n-j-1;
//             for(auto [num,freq]:preMap) {
//                 if(nums[j]==num) continue;
//                 ans += numberOfElementsAfter*freq;
//                 if(postMap.find(num)!=postMap.end()) ans -=
//                 postMap[num]*freq; if(postMap.find(nums[j])!=postMap.end())
//                 ans -= postMap[nums[j]]*freq;
//             }
//             preMap[nums[j]]++;
//         }
//         return ans;
//     }
// };

/*

4   4   2   4   3
                i





*/