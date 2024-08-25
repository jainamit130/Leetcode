long long modExp(int base,int exp,int mod){
    if(base==1 || exp==0){
        return 1;
    }

    long long half= modExp(base,exp/2,mod)%mod;
    half=(half*half)%mod;

    if(exp%2!=0){
        half = (half * base) % mod;  
    }
    return half;
}

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1){
            return nums;
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int maxE = INT_MIN;
        int n=nums.size();
        int mod = 1e9+7;
        // O(n log n)
        for(int i=0;i<n;i++){
            maxE=max(maxE,nums[i]);
            pq.push({nums[i],i});
        }

        while(k && maxE>=(long long)pq.top()[0]*multiplier){
            pq.push({pq.top()[0]*multiplier,pq.top()[1]});
            pq.pop();
            k--;
        }

        int p = k/n;
        int remK = k%n;
        vector<vector<int>> vec;
        while(!pq.empty()){
            vec.push_back(pq.top());
            pq.pop();
        }

        // For Even Distribution
        for(int i=0;i<n && p>0;i++){
            vec[i][0]=vec[i][0]*modExp(multiplier,p,mod)%mod;
        }

        // For remaining K
        for(int i=0;i<remK;i++){
            vec[i][0]=(long long)vec[i][0]*multiplier%mod;
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[vec[i][1]]=vec[i][0];
        }
        return ans;
    }
};


/*

0   1   2   3   4
2   1   3   5   6

max: 6       
minHeap: 4,0     4,1     5,3    6,2    6,4
vec: 4,0     4,1     5,3    6,2    6,4
k= 4

n = 5

p = k/n = 52/5 = 10

remK= k%n= 52 % 5 = 2

Multiply each element by multiplier 10 times = val * pow(multiplier,p)






*/