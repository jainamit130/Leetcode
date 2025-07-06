using ll = long long;
#define lc (x << 1)
#define rc (x << 1) | 1
int N;
vector<array<ll, 4>> ST;
// 0 -> both first and last
// 1 -> first but not last
// 2 -> not first but last
// 3 -> not first and not last

array<ll, 4> combine(array<ll, 4> lcVal, array<ll, 4> rcVal)
{
    array<ll, 4> ans;
    ans[0] = max(lcVal[0] + rcVal[2], lcVal[1] + max(rcVal[2], rcVal[0]));
    ans[1] = max(lcVal[0] + rcVal[3], lcVal[1] + max(rcVal[1], rcVal[3]));
    ans[2] = max(lcVal[2] + rcVal[2], lcVal[3] + max(rcVal[0], rcVal[2]));
    ans[3] = max(lcVal[2] + rcVal[3], lcVal[3] + max(rcVal[1], rcVal[3]));
    return ans;
}

array<ll, 4> query(int L, int R, int x = 1, int l = 1, int r = N + 1)
{
    // Base Case
    if (l >= R or r <= L) return {0ll,0ll,0ll,0ll};
    if (l >= L and r <= R) return ST[x];
    int mid = (l + r) / 2;
    // Combine
    array<ll, 4> ans = combine(query(L, R, lc, l, mid), query(L, R, rc, mid, r));
    return ans;
}

void update(int pos, int val, int x = 1, int l = 1, int r = N + 1)
{
    // no overlap
    if (pos < l or pos >= r) return;
    if (l == r - 1)
    {
        ST[x][0] = val;
        ST[x][1] = ST[x][2] = ST[x][3] = 0;
        return;
    }
    int mid = (l + r) / 2;
    update(pos, val, lc, l, mid);
    update(pos, val, rc, mid, r);

    // pass the update information to ancestors
    ST[x] = combine(ST[lc], ST[rc]);
}


class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        
        ll ans = 0;
        int n = nums.size(); 
        N = n+1;
        ST.assign(4*N, {0ll,0ll,0ll,0ll});
        // 1-based indexed seg tree
        for (int i=0; i<n; i++) update(i+1, nums[i]);
        
        for (auto q:queries)
        {
            int p = q[0], x = q[1];
            update(p+1, x);
            auto cur = query(1,n+1);
            ans += max({cur[0], cur[1], cur[2], cur[3]});
        }
        return ans%1000000007;
    }
};