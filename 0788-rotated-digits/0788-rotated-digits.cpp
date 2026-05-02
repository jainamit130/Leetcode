class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        unordered_set<int> unchanged = {0,1,8};
        unordered_set<int> changed = {2,5,6,9};
        unordered_map<int,pair<bool,bool>> cache;
        for(int i=1;i<=n;i++) {
            int num = i;
            int eligible = 0;
            int flag = 1;
            while(num) {
                if(cache.find(num)!=cache.end()) {
                    eligible = cache[num].first;
                    flag = cache[num].second;
                    break;
                }
                int t = num % 10;
                if(changed.find(t)!=changed.end()) {
                    eligible = 1;
                } else if(unchanged.find(t)==unchanged.end()) {
                    flag = 0;
                    break;
                }
                num/=10;
                cache[num] = {eligible,flag};
            }
            if(eligible) ans += flag;
        }
        return ans;
    }
};


/*




*/