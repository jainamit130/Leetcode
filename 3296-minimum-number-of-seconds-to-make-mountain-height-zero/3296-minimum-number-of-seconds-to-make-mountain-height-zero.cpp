class Solution {
public:
    using ll=long long;
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll start=1;
        ll end=1e17;
        ll ans=end;
        while(start<=end){
            ll mid=start+(end-start)/2;
            if(isValid(mid,workerTimes,mountainHeight)){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        } 
        return ans;
    }

    bool isValid(ll maxTime,vector<int>& rate,int height){
        long long totalReduction=0;
        for(auto n: rate){
            totalReduction+=binarySearchOnHeight(maxTime,n,height);
            if(totalReduction>=height){
                return true;
            }
        }
        return false;
    }

    int binarySearchOnHeight(ll maxTime,int n,int height){
        int start=0;
        int end=height;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            ll maxTimeForMidHeight = (ll)n*((ll)mid*(ll)(mid+1)/2);
            if(maxTimeForMidHeight<=maxTime){
                ans=mid;
                start=mid+1;
            } else {
                end=mid-1;
            }
        }
        return ans;
    }
};

/*

[10^6]

[10^5]

1 - 10^17

mid

((10^6*10^6)/2)*10^5 = 10^12+5 = 10^17

workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x

n*(mid*(mid+1)/2);

*/