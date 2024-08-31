class Solution {
    long long vectorToNumber(const vector<int>& num) {
        long long ans = 0;
        for (int digit : num) {
            ans = ans * 10 + digit;
        }
        return ans;
    }

    long long fact(int n){
        long long ans = 1;
        for(int i=2 ; i<=n ; i++) ans *= i;
        return ans;
    }

    long long calculatePermutations(map<int, int>& count) {
        int n = 0;
        for (auto& entry : count) {
            n += entry.second;
        }

        long long totalPermutations = fact(n);

        for (auto& entry : count) {
            totalPermutations /= fact(entry.second);
        }

        return totalPermutations;
    }

    // Function to calculate permutations starting with zero
    long long calculatePermutationsStartingWithZero(map<int, int> count) {
        if (count.find(0) == count.end() || count[0] == 0) {
            return 0;
        }

        count[0]--; // Fix one zero as the first digit

        long long permutationsWithZero = calculatePermutations(count);
        return permutationsWithZero;
    }

public:
    set<map<int,int>>m;
    void generatePalindrome(vector<int>& num, int left, int right, int k) {
        if (left > right) {
            long long palindrome = vectorToNumber(num);
            if (palindrome % k == 0) {
                map<int,int>temp;
                while(palindrome){
                    temp[palindrome%10]++;
                    palindrome /= 10;
                }
                m.insert(temp);
            }
            return;
        }

        // Set the current digit to all possible values from 0 to 9
        for (int digit = (left == 0) ? 1 : 0; digit <= 9; ++digit) {
            num[left] = num[right] = digit;
            generatePalindrome(num, left + 1, right - 1, k);
        }
    }

    long long countGoodIntegers(int n, int k) {
        vector<int> num(n);
        generatePalindrome(num, 0, n-1, k);
        long long ans = 0;

        for(auto i : m){
            long long totalPermutations = calculatePermutations(i),
            permutationsStartingWithZero = calculatePermutationsStartingWithZero(i),
            permutationsNotStartingWithZero = totalPermutations - permutationsStartingWithZero;
            
            ans += permutationsNotStartingWithZero;
        }
        return ans;
    }
};