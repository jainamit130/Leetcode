class Solution {
public:
    long long minDamage(int attackPower, std::vector<int>& enemyDamage, std::vector<int>& enemyHealth) {
        int numEnemies = enemyDamage.size();
        std::vector<std::pair<int, int>> enemyData;

        for (int i = 0; i < numEnemies; i++) {
            enemyData.emplace_back(enemyDamage[i], enemyHealth[i]);
        }

        sort(enemyData.begin(), enemyData.end(), [](auto lhs,auto rhs){
            if(lhs.first==rhs.first){
                return lhs.second<rhs.second;
            }
            return lhs.first>rhs.first;
        });

        long long totalDamage = 0;
        long long accumulatedDamage = 0;

        for (const auto& enemy : enemyData) {
            accumulatedDamage += enemy.first;
        }

        for (const auto& enemy : enemyData) {
            int hitsNeeded = (enemy.second + attackPower - 1) / attackPower;
            totalDamage += accumulatedDamage * hitsNeeded;
            accumulatedDamage -= enemy.first;
        }

        return totalDamage;
    }
};