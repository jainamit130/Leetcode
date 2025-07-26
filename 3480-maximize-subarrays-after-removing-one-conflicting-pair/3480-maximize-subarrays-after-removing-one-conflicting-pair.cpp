class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int maxRest = 0, secondMaxRest = 0;
        long long maxExtra = 0;
        long long valid = 0;
        unordered_map<int,priority_queue<int>> mp;
        for(auto pairs: conflictingPairs) {
            int smaller = min(pairs[0],pairs[1]), bigger = max(pairs[0],pairs[1]);
            mp[bigger].push(smaller); if(mp[bigger].size()>n) mp[bigger].pop();
        }
        vector<long long> extra(n+1,0);
        for(int i=1;i<=n;i++) {
            if(mp[i].size()>=1) {
                if(maxRest<=mp[i].top()) {
                    secondMaxRest = maxRest;
                    maxRest = mp[i].top();
                    mp[i].pop();
                } 
                if(mp[i].size()>=1 && mp[i].top()>secondMaxRest) {
                    secondMaxRest = max(secondMaxRest,mp[i].top());
                }
            }
            valid += (i-maxRest);
            extra[maxRest]+=maxRest-secondMaxRest;
            maxExtra = max(maxExtra,extra[maxRest]);
        }
        return valid + maxExtra;
    }

void printMap(const std::unordered_map<int, std::priority_queue<int>>& mp) {
    for (const auto& pair : mp) {
        std::cout << "Key: " << pair.first << " -> Values: ";

        // Make a copy of the priority_queue so we don't modify the original
        std::priority_queue<int> pq_copy = pair.second;
        while (!pq_copy.empty()) {
            std::cout << pq_copy.top() << " ";
            pq_copy.pop();
        }

        std::cout << std::endl;
    }
}
};