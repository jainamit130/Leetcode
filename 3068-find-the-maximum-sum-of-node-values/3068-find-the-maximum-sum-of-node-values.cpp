class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<pair<int,int>> xored(nums.size());
        for(int i=0;i<nums.size();i++){
            if((nums[i]^k)>nums[i])
                xored[i]={nums[i]^k,i};
            else
                xored[i]={nums[i],i};
            // cout<<xored[i].first<<endl;
        }
        sort(xored.begin(),xored.end(),[&](auto lhs,auto rhs){
            if(lhs.first==rhs.first){
                return nums[lhs.second]==lhs.first;
            }
            return lhs.first<rhs.first;
        });
        // for(auto a:xored){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        long long ans=0;
        for(int i=xored.size()-1;i>=1;i--)
            ans+=xored[i].first;
        if(xored.size()%2!=0)
            ans+=nums[xored[0].second];
        else
            ans+=xored[0].first;
        return ans;
    }
};

/*
0   1
1   2

1^3 || 2^3 = 01^11 || 10^11 = 10 || 01 = 10

0   1
2   1 = 3 (still 3)


0   2
1   1

1^3 = 2 2
3 -> 4



2   3

010^111 || 011^111 = 101 || 100
5   4
9



111 ^ 010 = 101


0 -> 1,2
1 -> 0
2 -> 0


*/