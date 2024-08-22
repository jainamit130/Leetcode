class Solution {
public:
    int real;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        for (auto n : nums) {
            target += n;
        }
        if (target % k != 0) {
            return false;
        }
        target /= k;
        real = target;
        
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> cache;  // 3D DP without `index`
        return solve(nums, target, k, 0, cache);
    }

    bool solve(vector<int>& nums, int target, int k, int visited, unordered_map<int, unordered_map<int, unordered_map<int, int>>>& cache) {
        if (k == 0 && visited == (1 << nums.size()) - 1) {
            return true;
        }

        if (k < 0 || target < 0) {
            return false;
        }

        // Check if the current state is memoized
        if (cache.find(k) != cache.end() && cache[k].find(target) != cache[k].end() && cache[k][target].find(visited) != cache[k][target].end()) {
            return cache[k][target][visited];
        }

        bool ans = false;
        for (int i = 0; i < nums.size(); i++) {
            // Skip if already visited
            if ((visited >> i) & 1) continue;

            // Mark the element as visited
            visited = visited | (1 << i);

            // Recur for the next element
            if (target - nums[i] == 0) {
                ans = ans || solve(nums, real, k - 1, visited, cache);
            } else {
                ans = ans || solve(nums, target - nums[i], k, visited, cache);
            }

            // Unmark the element (backtracking)
            visited = visited & (~(1 << i));
        }

        // Memoize the result for the current state
        cache[k][target][visited] = ans;
        return ans;
    }
};

// class Solution {
// public:
//     int real;
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int target=0;
//         for(auto n:nums){
//             target+=n;
//         }
//         if(target%k!=0){
//             return false;
//         }
//         target/=k;
//         real=target;
//         unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>> cache; 
//         return solve(nums,0,target,k,0,cache);
//     }

//     bool solve(vector<int>& nums,int index,int target,int k,int visited,unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>>& cache){
//         if(k==0 && visited==(1 << nums.size()) - 1){
//             return true;
//         }

//         if(index>=nums.size() || k<0 || target<0 || (visited >> index) & 1){
//             return false;
//         }

//         if(cache.find(index)!=cache.end() && cache[index].find(k)!=cache[index].end() && cache[index][k].find(target)!=cache[index][k].end() && cache[index][k][target].find(visited)!=cache[index][k][target].end()){
//             return cache[index][k][target][visited];
//         }

//         bool ans=false;
//         visited=visited|(1<<index);
//         for(int i=0;i<nums.size();i++){
//             if(target-nums[i]==0){
//                 ans=ans||solve(nums,i+1,real,k-1,visited,cache);
//             }
//             else {
//                 ans=ans||solve(nums,i+1,target-nums[i],k,visited,cache);
//             }
//         }
//         visited=visited&(~(1<<index));
//         return cache[index][k][target][visited]=ans;
//     }
// };


/*

4   3   2   3   5   2   1
i

4

4   3

4   3   2

4   3   2   3



  



*/