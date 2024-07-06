class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        int i=0,j=enemyEnergies.size()-1;
        long long ans=0;
        while(i<=j){
            if(enemyEnergies[i]>currentEnergy){
                if(ans==0){
                    return 0;
                }
                currentEnergy+=enemyEnergies[j];
                j--;
            } else {
                ans=ans+(currentEnergy/enemyEnergies[i]);
                currentEnergy=currentEnergy%enemyEnergies[i];
            }
        }
        return ans;
    }
};