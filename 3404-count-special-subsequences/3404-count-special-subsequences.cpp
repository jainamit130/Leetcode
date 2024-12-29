class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        map<pair<int,int>,vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n-6;i++) {
            for(int j=i+2;j<n-4;j++) {
                auto ratio = getRatio(nums[i],nums[j]);
                mp[ratio].push_back(j);
            }
        }

        long long ans = 0;
        for(int i=n-1;i>=6;i--) {
            for(int j=i-2;j>=4;j--) {
                auto ratio = getRatio(nums[i],nums[j]);
                if(mp.find(ratio)!=mp.end()) {
                    sort(mp[ratio].begin(),mp[ratio].end());
                    int index = lower_bound(mp[ratio].begin(),mp[ratio].end(),j-1)-mp[ratio].begin();
                    ans=ans+1LL*index;
                }
            }
        }
        return ans;
    }

    pair<int,int> getRatio(int a,int b) {
        for(int i=2;i<=min(a,b);i++) {
            while(a%i==0 && b%i==0) {
                a/=i;
                b/=i;
            }
        }
        return {a,b};
    }
};


/*

3   3 => 1,3   1,3 => 1  9 ; 9  1 ; 3  3
                   => 




*/