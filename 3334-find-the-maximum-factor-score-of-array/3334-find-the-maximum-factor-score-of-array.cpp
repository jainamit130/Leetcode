

class Solution {
public:
    int calculateGCD(const vector<int>& nums) {
        int gcd_val = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            gcd_val = gcd(gcd_val, nums[i]);
        }
        return gcd_val;
    }

    long long calculateLCM(const vector<int>& nums) {
        long long lcm_val = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            lcm_val = (lcm_val * nums[i]) / gcd(static_cast<long long>(lcm_val), static_cast<long long>(nums[i]));
        }
        return lcm_val;
    }

    long long maxScore(vector<int>& nums) {
        int totalGCD = calculateGCD(nums);
        long long totalLCM = calculateLCM(nums);

        long long maxFactorScore = 1LL * totalGCD * totalLCM;
        
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> temp=nums;
            temp.erase(temp.begin()+i);

            if (!temp.empty()) {
                int gcd = calculateGCD(temp);
                long long lcm = calculateLCM(temp);
                maxFactorScore = max(maxFactorScore, 1LL * gcd * lcm);
            }
        }
        
        return maxFactorScore;
    }
};
