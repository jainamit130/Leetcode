class Solution {
public:
    using ll=long long;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll start=1;
        ll end=1e16;
        ll ans=end;
        while(start<=end){
            ll mid = start + (end-start)/2;
            if(isValid(mid,mountainHeight,workerTimes)){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        return ans;
    }

    bool isValid(ll maxTime,int height,vector<int>& rate){
        ll totalReduction = 0;
        for(auto n:rate){
            totalReduction += maxReductionForWorker(n,maxTime,height);
            if(totalReduction>=height){
                return true;
            }
        }
        return false;
    }

    int maxReductionForWorker(int n,ll maxTime,int height) {
        int start = 0;
        int end = height;
        int ans=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            ll maxPossibleTimeForWorker = (ll)n*((ll)mid*(mid+1)/2);
            if(maxPossibleTimeForWorker<=maxTime){
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

MID => fixed time => maxPossible Time

start = 1
end = ?

10^6*(10^5 * 10^5)/2 = 10^16


*/

// class Solution {
// public:
//     using ll=long long;
//     long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
//         priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
//         for(auto n: workerTimes){
//             pq.push({n,n,1});
//         }

//         ll ans=0;
//         while(mountainHeight){
//             ll currRate = pq.top()[0];
//             int original = pq.top()[1];
//             int usage = pq.top()[2];
//             pq.pop();
//             ans=currRate;
//             usage++;
//             currRate += (ll)original * usage;
//             pq.push({currRate,original,usage});
//             mountainHeight--;
//         }
//         return ans;
//     }
// };


/*

MinHeap: 

1 => use => 1+1*2 => use => 3+1*3

heap: <currRate,original,usage>


*/