class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        vector<vector<long long>> cache(n+1,vector<long long>(2,-1));
        return max(solve(energyDrinkA,energyDrinkB,0,0,cache),solve(energyDrinkA,energyDrinkB,0,1,cache));
    }

    long long solve(vector<int>& energyDrinkA, vector<int>& energyDrinkB,int i,int lastUsed,vector<vector<long long>>& cache){
        if(i>=energyDrinkA.size()){
            return 0;
        }
        
        if(cache[i][lastUsed]!=-1){
            return cache[i][lastUsed];
        }

        long long ans=0;
        if(lastUsed==0){
            ans=max(ans,energyDrinkA[i]+solve(energyDrinkA,energyDrinkB,i+1,0,cache));
            ans=max(ans,solve(energyDrinkA,energyDrinkB,i+1,1,cache));
        } else {
            ans=max(ans,energyDrinkB[i]+solve(energyDrinkA,energyDrinkB,i+1,1,cache));
            ans=max(ans,solve(energyDrinkA,energyDrinkB,i+1,0,cache));
        }
        return cache[i][lastUsed]=ans;
    }
};