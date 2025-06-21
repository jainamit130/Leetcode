class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        const int MAXN = 50001;
        vector<bool> isPrime(MAXN, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < MAXN; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < MAXN; j += i)
                    isPrime[j] = false;
            }
        }

        int n = nums.size();
        int count = 0;
        deque<int> maxQ, minQ;
        int left = 0, primeCount = 0;

        for (int right = 0; right < n; ++right) {
            int num = nums[right];

            if (isPrime[num]) {
                ++primeCount;

                while (!maxQ.empty() && nums[maxQ.back()] < num) maxQ.pop_back();
                maxQ.push_back(right);

                while (!minQ.empty() && nums[minQ.back()] > num) minQ.pop_back();
                minQ.push_back(right);
            }

            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > k) {
                if (isPrime[nums[left]]) {
                    if (maxQ.front() == left) maxQ.pop_front();
                    if (minQ.front() == left) minQ.pop_front();
                    --primeCount;
                }
                ++left;
            }

            if (primeCount >= 2) {
                int p = 0;
                for (int i = right; i >= left; --i) {
                    if (isPrime[nums[i]]) ++p;
                    if (p >= 2) {
                        count += (i - left + 1);
                        break;
                    }
                }
            }
        }

        return count;
    }
};