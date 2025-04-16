class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0,j=0;
        long long ans = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        int currPairs = 0;
        while(j<n) {
            while(j<n && currPairs<k) {
                updateCurrPairs(currPairs,mp,nums[j],1);
                j++;
            }

            while(i<j && currPairs>=k) {
                ans += n-j+1;
                updateCurrPairs(currPairs,mp,nums[i],0);
                i++;
            }
        }
        return ans;
    }

    void updateCurrPairs(int& currPairs,unordered_map<int,int>& mp,int& val,int isGain) {
        if(mp.find(val)!=mp.end()) {
            currPairs -= getContribution(mp[val]);
        }
        if(isGain) {
            mp[val]++;
        } else {
            mp[val]--; if(mp[val]==0) mp.erase(val);
        }
        if(mp.find(val)!=mp.end()) {
            currPairs += getContribution(mp[val]);
        }
        return;
    }

    int getContribution(int freq) {
        return freq*1LL*(freq-1)/2;
    }
};


/*


1   1   1   1   1   1


array,k => vector<int> , int

k pairs of same values

1   1   1   1   1



1 -> 5 => 5*4/2 = 10


3   1   4   3   2   2   4

k = 2

                i                                       
                                                        j
2   1   3   1   2   2   3   3   2   2   1   1   1   3   1

6 + 10 + 12 + 12 + 10 + 6 

12

1 -> 4
2 -> 3
3 -> 3

*/