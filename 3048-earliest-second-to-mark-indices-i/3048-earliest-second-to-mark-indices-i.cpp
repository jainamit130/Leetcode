class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n=nums.size();
        int m=changeIndices.size();
        int start=n;
        int end=m;
        int ans=INT_MAX;
        while(start<=end){
            int time=(start+end)/2;
            if(allIndicesMarked(time,nums,changeIndices)){
                ans=min(ans,time);
                end=time-1;
            } else {
                start=time+1;
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }

    bool allIndicesMarked(int time,vector<int>& nums,vector<int>& changedIndices){
        int n=nums.size();
        map<int,int> mp;
        vector<int> lastOccur(n,-1);
        for(int i=0;i<time;i++){
            int index=changedIndices[i];
            lastOccur[index-1]=i;
        }

        for(int i=0;i<lastOccur.size();i++){
            if(lastOccur[i]==-1){
                return false;
            }
            mp[lastOccur[i]]=i;
        }

        int timePassed=0;
        for(auto [index,pos]:mp){
            int reqTime=nums[pos]+1;
            if(timePassed+reqTime>index+1){
                return false;
            } 
            timePassed+=reqTime;
        }
        return true;
    }
};