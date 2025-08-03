class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int,int,long long>> decreasing;
        long long sum = 0;
        int start = -1;
        for(int i=1;i<n;i++) {
            if(nums[i-1]>nums[i]) {
                if(start==-1) start = i-1;
                sum += nums[i-1];
            } else {
                if(start!=-1) {
                    sum += nums[i-1];
                    decreasing.emplace_back(start,i-1,sum);
                }
                sum = 0;
                start = -1;
            }
        }

        long long ans = LLONG_MIN;
        for(auto [start,end,sum]:decreasing) {
            if(start-1>=0 && nums[start-1]<nums[start]) {
                int i = start-1;
                sum += nums[i];
                while(i>0 && nums[i-1]<nums[i] && nums[i-1]>0) {
                    sum += nums[i-1];
                    i--;
                }

                if(end+1<nums.size() && nums[end]<nums[end+1]) {
                    int j = end+1;
                    sum += nums[j];
                    while(j+1<n && nums[j]<nums[j+1]) {
                        ans = max(ans,sum);
                        sum += nums[j+1];
                        j++;
                    }
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};