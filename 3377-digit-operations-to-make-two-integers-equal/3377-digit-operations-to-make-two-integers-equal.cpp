class Solution {
public:
    void seive(vector<bool>& primes) {
        primes[0] = primes[1] = false;
        for (int i = 2; i * i < primes.size(); ++i) {
            if (primes[i]) {
                for (int j = i * i; j < primes.size(); j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    int minOperations(int n, int m) {
        vector<bool> primes(1e5 + 1, true);
        seive(primes);

        if (primes[n] || primes[m]) return -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({n, n});  

        vector<bool> vis(1e4 + 1, false);  
        vis[n] = true;  

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int sum = top.first; 
            int curr = top.second;  

            if (curr == m) {
                return sum; 
            }

            string s = to_string(curr);

            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '9') {
                    string temp = s;
                    temp[i] = temp[i] + 1;
                    int num = stoi(temp);

                    if (!primes[num] && !vis[num]) {
                        vis[num] = true;
                        pq.push({sum + num, num});
                    }
                }

                if (s[i] != '0') {
                    string temp = s;
                    temp[i] = temp[i] - 1;
                    int num = stoi(temp);

                    if (!primes[num] && !vis[num]) {
                        vis[num] = true;
                        pq.push({sum + num, num});
                    }
                }
            }
        }

        return -1; 
    }
};