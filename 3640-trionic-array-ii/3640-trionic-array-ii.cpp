class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int start = -1;
        long long ans = LLONG_MIN;
        // get all the decreasing subarrays
        // start from index = 1(because i need atleast 2 elements to consider it
        // as decreasing)
        int index = 1;
        while (index<n) {
            // decreasing
            if (nums[index - 1] > nums[index]) {
                if (start == -1)
                    start = index - 1;
                sum += nums[index - 1];
            } else {
                if (start != -1) {
                    sum += nums[index - 1];
                    int end = index - 1;
                    // expand increasing 1 and increasing 2
                        // expand increasing 1 backward
                        // first check if valid or not
                        if (start - 1 >= 0 && nums[start - 1] < nums[start]) {
                            int i = start - 1;
                            // atleast once included
                            sum += nums[i];
                            while (i > 0 && nums[i - 1] < nums[i] &&
                                   nums[i - 1] > 0) {
                                sum += nums[i - 1];
                                i--;
                            }

                            // expand increasing 2 forward
                            // first check if valid or not
                            if (end + 1 < n && nums[end] < nums[end + 1]) {
                                int j = end + 1;
                                // atleast once included
                                sum += nums[j];
                                while (j + 1 < n && nums[j] < nums[j + 1]) {
                                    // subarray is guranteed to be trionic at
                                    // this point
                                    ans = max(ans, sum);
                                    sum += nums[j + 1];
                                    j++;
                                }
                                ans = max(ans, sum);
                            }
                        }
                }
                sum = 0;
                start = -1;
            }
            index++;
        }

        return ans;
    }
};

/*



Increasing 1
Decreasing
Increasing 2

Case 1 => nums[i]<nums[i+1]; nums[i]==nums[i+1]; nums[i]>nums[i+1]


p   ......  q

Conclsuions:
1. decreasing is the foundation => reason being its fixed as the mid part
leaving us with no choice
2. elements can be negative
3. get all the decreasing subarrays
4. expand backwards to get increasing 1
    i. expand till its valid => nums[i-1]<nums[i] (atleast once)
    ii. expand till things are positive (nums[i-1]>0)
5. expand forward to get increasing 2
    i. expand till its valid => nums[j]<nums[j+1] (atleast once)
    ii. keep expanding till i can (be greedy)
    iii. at every expansion keep maximizing the answer
6. have a ans globally and keep maximizing


Dry Run

0    1   2   3   4   5   6
0   -2  -1  -3  0   2   -1
    s           e


Decreasing
Start   End   Total
0       1     -2
2       3     -4




start = 0 => expand backwards
end = 1


*/