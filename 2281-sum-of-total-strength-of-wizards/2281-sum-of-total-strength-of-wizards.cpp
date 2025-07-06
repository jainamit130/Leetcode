class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int mod = 1e9 + 7;
        int n = strength.size();
        vector<int> prefix1D(1);
        vector<int> prefix2D(1);
        for (auto s : strength)
            prefix1D.push_back((prefix1D.back() + s) % mod);
        for (int i = 0; i < prefix1D.size(); i++)
            prefix2D.push_back((prefix2D.back() + prefix1D[i]) % mod);
        vector<int> leftBound(n);
        vector<int> rightBound(n);
        stack<int> st;
        getBound(leftBound, st, 1, strength);
        getBound(rightBound, st, -1, strength);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int le = i - leftBound[i];
            int re = rightBound[i] - i;

            int p1 =
                ((prefix2D[rightBound[i] + 1] - prefix2D[i + 1]) * 1LL * le) %
                mod;
            int p2 =
                ((prefix2D[i + 1] - prefix2D[leftBound[i] + 1]) * 1LL * re) %
                mod;
            if (p2 < 0)
                p2 += mod;
            int p = (p1 - p2 + mod) % mod;
            p = (p * 1LL * strength[i]) % mod;
            ans = (ans + p) % mod;
        }

        return ans;
    }

    void getBound(vector<int>& bound, stack<int> st, int dir,
                  vector<int>& arr) {
        int n = arr.size();
        int index = (dir == 1) ? 0 : n - 1;
        while (n--) {
            while (!st.empty() && ((dir == -1 && arr[st.top()] > arr[index]) ||
                                   (dir == 1 && arr[st.top()] >= arr[index]))) {
                st.pop();
            }
            bound[index] =
                st.empty() ? ((dir == -1) ? arr.size() : -1) : st.top();
            st.push(index);
            index += dir;
        }
        return;
    }
};

/*
i   0   1   2   3
s   1   3   1   2
0   1   4   5   7
0   1   5   10  17
l   0   1   1   3
r   3   1   3   3

1   3   1   2
            i


Stack: 1,0  3,1



a   b   c   d   e   f   g
1   3   4   2   3   4   1
i



LB                                  RB
L1  L2  L3  L4  L5  i   R1  R2  R3  R4
0   PL1 PL2 PL3 PL4 PL5 Pi  PR1 PR2 PR3 PR4


P(i+1) - P(L1-1)
P(i+1) - P(L2-1)
P(i+1) - P(L3-1)
P(i+1) - P(L4-1)
P(i+1) - P(L5-1)

P(R1+1) - P(L1-1)
P(R1+1) - P(L2-1)
P(R1+1) - P(L3-1)
P(R1+1) - P(L4-1)
P(R1+1) - P(L5-1)

P(R2+1) - P(L1-1)
P(R2+1) - P(L2-1)
P(R2+1) - P(L3-1)
P(R2+1) - P(L4-1)
P(R2+1) - P(L5-1)

P(R3+1) - P(L1-1)
P(R3+1) - P(L2-1)
P(R3+1) - P(L3-1)
P(R3+1) - P(L4-1)
P(R3+1) - P(L5-1)

P(R4+1) - P(L1-1)
P(R4+1) - P(L2-1)
P(R4+1) - P(L3-1)
P(R4+1) - P(L4-1)
P(R4+1) - P(L5-1)

5*(P(R1+1) + P(R2+1) + P(R3+1) + P(R4+1))
-
4*(P(L1)+P(L2)+P(L3)+P(L4))

no of elements on left * (PP[RB+1]-PP[i-1])
-
no of elements on right * (PP[i+1]-PP[LB-1])



*/