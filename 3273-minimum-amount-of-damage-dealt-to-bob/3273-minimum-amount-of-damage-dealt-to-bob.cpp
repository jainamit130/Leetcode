class Solution {
public:
    long long minDamage(int attackPower, std::vector<int>& enemyDamage, std::vector<int>& enemyHealth) {
        int numEnemies = enemyDamage.size();
        std::vector<std::pair<int, int>> enemyData;

        for (int i = 0; i < numEnemies; i++) {
            enemyData.emplace_back(enemyDamage[i], enemyHealth[i]);
        }

        auto weightComparator = [attackPower](const std::pair<int, int>& first, const std::pair<int, int>& second) {
            long long weightFirst = static_cast<long long>(first.first) * ((second.second + attackPower - 1) / attackPower);
            long long weightSecond = static_cast<long long>(second.first) * ((first.second + attackPower - 1) / attackPower);
            return weightFirst > weightSecond;
        };

        std::sort(enemyData.begin(), enemyData.end(), weightComparator);

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