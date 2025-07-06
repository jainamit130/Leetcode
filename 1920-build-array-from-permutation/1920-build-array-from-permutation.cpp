class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        }
        return nums;
    }
};

/*
5   0   1   2   3   4

0   1   2   3   4   5
0   0   0   0   0   1

temp = 4

*/