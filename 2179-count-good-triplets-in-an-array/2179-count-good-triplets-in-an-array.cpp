#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered set definition
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> nums1ValToIndexMp(n);
        ordered_set<int> preOrder;
        for (int i = 0; i < n; i++) {
            nums1ValToIndexMp[nums1[i]] = i;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int val = nums2[i];
            int index = nums1ValToIndexMp[val];
            int elementsBefore = preOrder.order_of_key(index);
            int elementsAfter = (n - index - 1) - (preOrder.size() - elementsBefore);
            ans += 1LL * elementsBefore * elementsAfter;
            preOrder.insert(index);
        }

        return ans;
    }
};



/*
0   1   2   3   4   
4   0   1   3   2

0   1   2   3   4
4   1   0   2   3


4 -> 0
0 -> 1
1 -> 2
3 -> 3
2 -> 4


0   2   1   4   3
0   1   2   3   4


Segment Tree

                0-4(5)
    0-2                     3-4()


0   1   2   3   4
1   2   4   3   0

0   1   2   3   4
4   1   0   2   3


before=> 
after=> 
*/