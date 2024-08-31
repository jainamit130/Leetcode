class Solution {
public:
    long long minDamage(int attackPower, std::vector<int>& enemyDamage, std::vector<int>& enemyHealth) {
        int numEnemies = enemyDamage.size();
        std::vector<std::pair<int, int>> enemyData;

        long long accumulatedDamage = 0;
        for (int i = 0; i < numEnemies; i++) {
            accumulatedDamage += enemyDamage[i];
            enemyData.emplace_back(enemyDamage[i], enemyHealth[i]);
        }

        sort(enemyData.begin(), enemyData.end(), [&](auto lhs,auto rhs){
            auto dps1 = 1.0*(lhs.first)/ceil((1.0*lhs.second)/(1.0*attackPower));
            auto dps2 = 1.0*(rhs.first)/ceil((1.0*rhs.second)/(1.0*attackPower));
            if(dps1==dps2){
                if(lhs.first==rhs.first){
                    return lhs.second<rhs.second;
                } else {
                    return lhs.first>rhs.first;
                }
            }
            return dps1>dps2;
        });

        long long totalDamage = 0;

        for (const auto& enemy : enemyData) {
            int hitsNeeded = ceil((1.0*enemy.second) / (1.0*attackPower));
            totalDamage += accumulatedDamage * hitsNeeded;
            accumulatedDamage -= enemy.first;
        }

        return totalDamage;
    }
};