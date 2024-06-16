class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxReach = 0;
        int ans=0;
        for(int i=0;i<nums.size() && maxReach<n;){
            if(nums[i]>maxReach+1){
                ans++;
            } else {
                i++;
            }
            maxReach+=maxReach+1;
        }
        while(maxReach<=n){
            ans++;
            maxReach+=(long)maxReach+1;
        }
        return ans;
    }
};


/*


33

(1)   (2)   (3)   (4)   (5)   (6)   (7)   (8)   (9)   (10)  (11)  (12)  (13)  (14)  (15)  (16)  (17)  (18)  (19)  (20)

1 => 1   
2 => 2 (ans)
3 => 1,2
4 => 4 (ans)
5 => 5
6 => 2  4
7 => 1  2   4
8 => 1  2   5
9 => 4  5
10 => 1 4  5
11 => 1  10
12 => 2  10
13 => 1  2  10
14 => 4  10
15 => 5  10
16 => 2  4  10
17 => 1  2  4  10
18 => 1  2  5  10
19 => 4  5  10
20 => 1  4  5  10


*/