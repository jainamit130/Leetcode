class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        long long ans=power[0];
        vector<long long> maxDamageAtIndex(power.size());
        maxDamageAtIndex[0]=power[0];
        int duplicatesTillCurrentIndex = 1;
        for(int i=1;i<power.size();i++){
            if(power[i]!=power[i-1]){
                duplicatesTillCurrentIndex=0;
            } 
            duplicatesTillCurrentIndex++;
            maxDamageAtIndex[i]=maxDamageAtIndex[i]+(long long)power[i]*duplicatesTillCurrentIndex;
            //binarySearch
            int safeIndex = lower_bound(power.begin(),power.begin()+i,power[i]-2)-power.begin()-1;
            if(safeIndex>-1)
                maxDamageAtIndex[i]=maxDamageAtIndex[i]+maxDamageAtIndex[safeIndex];
            maxDamageAtIndex[i]=max(maxDamageAtIndex[i],ans);
            ans=max(ans,maxDamageAtIndex[i]);
        }
        return ans;
    }
};