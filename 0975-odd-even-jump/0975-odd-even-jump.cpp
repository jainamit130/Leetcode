#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef pair<int,int> pii;

class Solution {
public:   
    int oddEvenJumps(vector<int>& arr) {
        vector<int> indexes(100001, -1);
        ordered_set st;
        vector<pii> eveOdd(arr.size(), {0, 0});
        eveOdd[arr.size() - 1] = {1, 1}; 
        vector<pii> firstBigFirstSmall(arr.size(), {-1, -1}); 
        int ans = 1;
        indexes[arr.back()] = arr.size() - 1;
        st.insert(arr.back());
        for (int i = arr.size() - 2; i >= 0; i--) {
            int firstBig = -1;
            int firstSmall = -1;
            int order = st.order_of_key(arr[i]);
            if (order != 0)
                firstSmall = indexes[*st.find_by_order(order - 1)];
            auto it = st.upper_bound(arr[i]);
            if (it != st.end()) {
                firstBig = indexes[*it];
            }
            firstBigFirstSmall[i] = {firstBig, firstSmall};
            if (indexes[arr[i]] != -1) {
                cout<<indexes[arr[i]]<<" "<<i<<endl;
                firstBigFirstSmall[i] = {indexes[arr[i]], indexes[arr[i]]};
                firstSmall = indexes[arr[i]];
                firstBig = indexes[arr[i]];
            }

            // For Even Check FirstSmall's Odd
            if (firstSmall != -1) {
                eveOdd[i].first = eveOdd[firstSmall].second;
            }

            // For Odd Check FirstBig's Even
            if (firstBig != -1) {
                eveOdd[i].second = eveOdd[firstBig].first;
            }

            if (eveOdd[i].second) {
                ans++;
            }
            st.insert(arr[i]);
            indexes[arr[i]]=i;
        }
        return ans;
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