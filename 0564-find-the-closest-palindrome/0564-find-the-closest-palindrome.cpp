class Solution {
public:
    string nearestPalindromic(string n) {
        int size = n.length();
        long long num = stoll(n); 

        auto createPalindrome = [](long long half, int length, bool isOdd) {
            string s = to_string(half);
            string rev = s;
            reverse(rev.begin(), rev.end());
            if (isOdd) {
                return stoll(s + rev.substr(1));
            } else {
                return stoll(s + rev);
            }
        };

        long long firstHalf = stoll(n.substr(0, (size + 1) / 2));
        bool isOdd = (size % 2 == 1);

        vector<long long> candidates;
        candidates.push_back(createPalindrome(firstHalf, size, isOdd));
        candidates.push_back(createPalindrome(firstHalf - 1, size, isOdd));
        candidates.push_back(createPalindrome(firstHalf + 1, size, isOdd));
        candidates.push_back(pow(10, size) + 1);
        candidates.push_back(pow(10, size - 1) - 1);

        long long closest = LLONG_MAX;
        for (long long candidate : candidates) {
            if (candidate != num) { 
                if (abs(candidate - num) < abs(closest - num) || 
                   (abs(candidate - num) == abs(closest - num) && candidate < closest)) {
                    closest = candidate;
                }
            }
        }

        return to_string(closest);
    }
};