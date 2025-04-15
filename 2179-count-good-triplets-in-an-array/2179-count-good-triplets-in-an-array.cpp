#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> nums1ValToIndexMp(n);
        ordered_set<int> preOrder;
        ordered_set<int> postOrder;
        for(int i=0;i<n;i++) {
            nums1ValToIndexMp[nums1[i]]=i;
            postOrder.insert(i);
        }
        long long ans = 0;
        for(int i=0;i<n;i++) {
            int index = nums1ValToIndexMp[nums2[i]];
            int elementsBefore = preOrder.order_of_key(index);
            postOrder.erase(index);
            int elementsAfter = postOrder.size() - postOrder.order_of_key(index);
            ans += 1LL*elementsBefore*elementsAfter;
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


*/