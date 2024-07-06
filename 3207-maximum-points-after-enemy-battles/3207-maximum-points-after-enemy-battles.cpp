class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        int points=0;
        int n=enemyEnergies.size();
        int i=0,j=n-1;
        while(i<=j){
            if(currentEnergy<enemyEnergies[i]){
                if(points==0){
                    return 0;
                }
                currentEnergy+=enemyEnergies[j];
                j--;
            } else {
                points++;
                currentEnergy-=enemyEnergies[i];
            }
        }
        return points;
    }
};

/*

points=1
Choose a enemy eng
    curr>=enemy => curr-=enmy
    curr<enemy => 
                    if(points>=1){
                        curr+=enemy
                        mark enemy
                    }

2   2   3
ij
current=1
points=3








*/