class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {

        int ans = 0;
        for (int i = 0; i < batteryPercentages.size(); i++) {
            if (batteryPercentages[i] > 0) {
                ans++;
                for (int j = i; j < batteryPercentages.size(); j++) {
                    batteryPercentages[j] = batteryPercentages[j] - 1;
                }
            }
        }
        return ans;
    }
};