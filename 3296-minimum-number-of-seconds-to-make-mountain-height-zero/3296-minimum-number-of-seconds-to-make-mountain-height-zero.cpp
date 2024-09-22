class Solution {
public:
    using ll=long long;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        for(auto n: workerTimes){
            pq.push({n,n,1});
        }

        ll ans=0;
        while(mountainHeight){
            ll currRate = pq.top()[0];
            int original = pq.top()[1];
            int usage = pq.top()[2];
            pq.pop();
            ans=currRate;
            usage++;
            currRate += (ll)original * usage;
            pq.push({currRate,original,usage});
            mountainHeight--;
        }
        return ans;
    }
};


/*

MinHeap: 

1 => use => 1+1*2 => use => 3+1*3

heap: <currRate,original,usage>


*/