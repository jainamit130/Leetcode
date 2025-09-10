class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            int reqVal = target-nums[i];
            if(mp.find(reqVal)!=mp.end()) {
                return {mp[reqVal],i};
            } 
            if(mp.find(nums[i])==mp.end()) mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};


/*
clarifications:
1. can array be empty? no atleast 2 elements guaranteed
2. can array have negative elements? that will be the follow up for now no
3. what do i need to return the indexes? so basically need to return a vector of size 2
4. dealing with only integers right? yes for now
5. nums vector<int> and target int would be provided? yes
6. can be duplicates? yes
7. multiple ans possible then ? no guaranteed to have exactly one solution

Ex:
6   2   7   1   1   4   3   5

target is 12


Approach:

Brute force is to run a 2d loop and simulate the exact thing
O(n^2)
O(1)


Optimised Approach:

1. Initialize a empty map that will contain val to index 
2. iterate the nums array
3. For every iteration check if the map contains the target-nums[index] in map if yes then return that 
4. update map only if the val is not present


O(n)
O(n)
*/