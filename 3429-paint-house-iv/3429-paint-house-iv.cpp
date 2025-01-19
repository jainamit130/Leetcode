class Solution {
public:
    vector<vector<vector<long long>>> cache;
    long long minCost(int n, vector<vector<int>>& cost) {
        cache.resize(n/2+1,vector<vector<long long>>(4,vector<long long>(4,-1)));
        return solve(cost,0,-1,-1);
    }

    long long solve(vector<vector<int>>& cost,int index,int lastCost1,int lastCost2) {
        if(index>=cost.size()/2) {
            return 0;
        }

        if(cache[index][lastCost1+1][lastCost2+1]!=-1) {
            return cache[index][lastCost1+1][lastCost2+1]; 
        }

        long long ans = LLONG_MAX;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(i!=j) {
                    if(lastCost1!=i && lastCost2!=j) {
                        ans=min(ans,cost[index][i]+cost[cost.size()-index-1][j]+solve(cost,index+1,i,j));
                    }
                }
            }
        }
        return cache[index][lastCost1+1][lastCost2+1]=ans;
    }
};


/*

3   5   7
6   2   9
4   8   1
7   3   5




*/