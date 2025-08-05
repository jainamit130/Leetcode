class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<bool> used(n, false);
        int ans = 0;
        
        for (int i = 0; i < fruits.size(); ++i) {
            bool placed = false;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) ans++;
        }
        
        return ans;
    }
};


/*

4   2   5



3 -> 1
4 -> 1
5 -> 1


*/