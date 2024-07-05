class Solution {
using IntPair = pair<int, int>; // {value, index}

// cache values
const int UNDEFINED = INT_MAX;
const int INVALID = 0;
const int VALID = 1;

// cache indexes
const int EVEN_JUMP = 0;
const int ODD_JUMP = 1;

// comparators
static bool ascendingCompare(const IntPair& a, const IntPair& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

static bool descendingCompare(const IntPair& a, const IntPair& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

public:
    // O(nlogn) time | O(n) space
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        
        // sort values and indexes to determine
        // next absolute greater and next absolute smaller
        vector<IntPair> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {arr[i], i};
        }
        sort(pairs.begin(), pairs.end(), ascendingCompare);
        vector<int> absoluteNextGreater = nextValuablePositions(pairs);
        
        sort(pairs.begin(), pairs.end(), descendingCompare);
        vector<int> absoluteNextSmaller = nextValuablePositions(pairs);

        // dp and base cases
        vector<vector<int>> dp(n, vector<int>(2, INVALID));
        dp[n - 1][EVEN_JUMP] = VALID;
        dp[n - 1][ODD_JUMP] = VALID;

        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int oddJumpIndex = absoluteNextGreater[i];
            int evenJumpIndex = absoluteNextSmaller[i];

            if (oddJumpIndex < n && dp[oddJumpIndex][EVEN_JUMP] == VALID) {
                dp[i][ODD_JUMP] = VALID;
            }
            if (evenJumpIndex < n && dp[evenJumpIndex][ODD_JUMP] == VALID) {
                dp[i][EVEN_JUMP] = VALID;
            }
            if (dp[i][ODD_JUMP] == VALID) {
                ++res;
            }
        }

        return res;
    }

    // monotonic stack
    vector<int> nextValuablePositions(vector<IntPair>& sortedPairs) {
        int n = sortedPairs.size();
        vector<int> res(n, UNDEFINED);
        stack<IntPair> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && sortedPairs[i].second > stk.top().second) {
                res[stk.top().second] = sortedPairs[i].second;
                stk.pop();
            }
            stk.push(sortedPairs[i]);
        }
        return move(res);
    }
};

/*

Jump= 1
            0   1   2   3   4
            2   3   1   1   4
                    i

Even        1   1   1   0   1
Odd         1   1   0   1   1
FirstB      1   4   3   4   -1
FirstS      3   3   3   -1  -1



            10  13  12  14  15
                     i

Even         0   0   0   0   1
Odd          0   0   0   1   1
FirstB       2   3   3   4  -1
FirstS      -1   2  -1  -1  -1

Monotonic Stack(Max bottom)
15  14  13  10


Monotonic Stack(Min bottom)
10



Jump= 1
            0   1   2   3   4   5   6   7
            1   2   3   2   1   4   4   5
                    i

Even        1   1   1   1   0   1   0   1
Odd         1   1   1   1   1   0   1   1 
FirstB      4   3   5   5   5   6   7   -1
FirstS      4   3   3   4   -1  6   -1  -1


            0   1   2   3 
            19  56  23  96
                    i

Even        0   1   0   1
Odd         1   1   1   1 
FirstB      2   3   3   -1
FirstS      -1  2   -1  -1
                           


*/