class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        map<pair<int,int>,vector<int>> mp;
        int n =nums.size();
        for(int p=0;p<n-6;p++) {
            for(int q=p+2;q<n-4;q++) {
                auto ratio = getRatio(nums[p],nums[q]);
                mp[ratio].push_back(q);
            }
        }

        for(auto& [key,vec]:mp) {
            sort(vec.begin(),vec.end());
        }

        long long ans = 0;
        for(int s=n-1;s>=6;s--) {
            for(int r=s-2;r>=4; r--) {
                auto ratio = getRatio(nums[s],nums[r]);
                if(mp.find(ratio)!=mp.end()) {
                    int index = lower_bound(mp[ratio].begin(),mp[ratio].end(),r-1)-mp[ratio].begin();
                    ans = ans + index;
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



nums[p]/nums[q]  =  nums[s]/nums[r]


x/y -> 1,8,8,5,5,11

m/n -> 
lower_bound search of index(m)-1


*/