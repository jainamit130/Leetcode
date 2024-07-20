class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int diff=abs(nums[i]-nums[n-i-1]);
            mp[diff]++;
        }
        int result=INT_MAX;
        
        vector<vector<int>> freqMp;
        for(auto [a,b]:mp){
            cout<<a<<" "<<b<<endl;
            freqMp.push_back({b,a});
        }

        sort(freqMp.begin(),freqMp.end());
        int i=freqMp.size()-1;
        int freq=-1;
        while(i>=0){
            if(freq==-1){
                freq=freqMp[i][0];
            } else {
                if(freqMp[i][0]!=freq && freqMp[i][1]!=15){
                    break;
                }
            }
            int targetDiff=freqMp[i][1];
            int ans=0;
            for(int i=0;i<n/2;i++){
                int diff=abs(nums[i]-nums[n-i-1]);
                if(diff!=targetDiff){
                    if(nums[n-i-1]-targetDiff>=0 || nums[n-i-1]+targetDiff<=k || nums[i]-targetDiff>=0 || nums[i]+targetDiff<=k){
                        ans+=1;
                    } else {
                        ans+=2;
                    }
                }
            }
            result=min(ans,result);
            i--;
        }
        return result;
    }
};