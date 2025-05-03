class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int m = nums.size();
        int n = 1;
        for(int i=0;i<m;i++) {
            // i -> 0
            int col = 0;
            int row = i;
            while(row>=0) {
                if(row+col==i && col<nums[row].size()) {
                    ans.push_back(nums[row][col]);
                }
                n=max(n,(int)nums[row].size());
                col++;
                row--;
            }
        }

        for(int i=1;i<n;i++) {
            // i -> 0
            int row = m-1;
            int col = i;
            while(row>=0) {
                if(row+col==i+m-1 && col<nums[row].size()) {
                    ans.push_back(nums[row][col]);
                }
                row--;
                col++;
            }
        }
        return ans;
    }
};

/*


14  12  19  16  9
13  14  15  8   11
11  13  1


00  01  02  03  04
1   2   3   4   5

10  11
6   7

20
8

30  31  32
9   10  11

40  41  42  43  44
12  13  14  15  16


*/