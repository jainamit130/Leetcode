class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remaindersFound;
        int currSum = 0;
        remaindersFound[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int remainder = currSum % k;

            if (remaindersFound.find(remainder) != remaindersFound.end()) {
                if (i - remaindersFound[remainder] >= 2) {
                    return true;
                }
            } else {
                remaindersFound[remainder] = i;
            }
        }
    }
};

    /*

    23  2   6   4   7



    1   2   12
    0   1   3   15

    0   1   0


    1   0
    0   1   1



    23  2   4   6   6
    23  25  29  35  41
    2   4   1   0   6

    map
    0 -> 1
    1 -> 1
    5 -> 4




    23  2   6   4   7
    23  25  35



    23  2   4   6   6
    23  25  29  35  41

    5   1   5   5   5

    23  2   4   6   7

    23  25  29  35  42

    5,11,17,23
    1,7,13,19



    */