class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> nums1;
        for(int i=0;i<n;i++) {
            nums1.push_back({nums[i],i});
        }
        sort(nums1.begin(),nums1.end());
        vector<queue<int>> groups;
        vector<int> mapping(n);
        for(int i=0;i<n;i++) {
            if(i==0 || nums1[i][0]-nums1[i-1][0]>limit) {
                queue<int> q;
                groups.push_back(q);
            }
            groups.back().push(nums1[i][0]);
            mapping[nums1[i][1]] = groups.size()-1;
        }

        vector<int> ans;
        for(int i=0;i<n;i++) {
            ans.push_back(groups[mapping[i]].front());
            groups[mapping[i]].pop();
        }
        return ans;
    }
};


/*
1   6   7   18  2   1


1 -> -1 to 3

5 -> 3 to 7

3 -> 1 to 5






*/