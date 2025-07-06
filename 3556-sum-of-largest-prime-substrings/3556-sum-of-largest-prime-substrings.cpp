class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> st;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<s.length();i++) {
            long long num = 0;
            for(int j=i;j<s.length();j++) {
                num = num * 10 + (s[j]-'0');
                if(st.find(num)==st.end() && isPrime(num)) {
                    st.insert(num);
                    pq.push(num);
                    if(pq.size()>3) pq.pop();
                }
            }
        }

        long long sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop(); 
        }
        return sum;
    }

    bool isPrime(long long n) {
        if(n<=1) return false;
        for(long long i=2;(i*i)<=n;i++) {
            if(n%i==0) return false;
        }
        return true;
    }
};

/*


at best for a given number => prime number => O(log n)

substrings => O(n^2 * log n)

set 
min heap => largest size 3

*/