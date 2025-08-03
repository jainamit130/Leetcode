class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.length();
        int start = 0, end = n-1, ans = -1;
        while(start<=end) {
            int mid = start + (end - start) / 2;
            if(isValid(mid,order,k)) {
                ans = mid;
                end = mid - 1;
            } else start = mid + 1;
        }
        return ans;
    }

    bool isValid(int index, vector<int>& order,int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<=index;i++) pq.push(order[i]); 
        int last = 0;
        long long ans = 0;
        while(!pq.empty()) {
            long long subAns = (pq.top()-last+1) * (order.size()-pq.top());
            ans += subAns;
            last = pq.top()+1;
            pq.pop(); 
        }
        return ans>=k;
    }
};


/*

C   A   T   


*   A   *

O(n log n  *  log n)

-1  0   1   2   3   4   5   6   7   8
*   *   a   b   g   d   e   *   f   *
6                                   9
9                                   6

6   0   3   2   4   1   7   5
8   



(index - last + 1) * (n - index)
(1 - 0 + 1) * (7 - 1)

a  *  b  c  *  d  e

a  *
a  *  b 
a  *  b  c
a  *  b  c  *
a  *  b  c  *  d
a  *  b  c  *  d  e
*
*  b 
*  b  c
*  b  c  *
*  b  c  *  d
*  b  c  *  d  e
b  c  * 
b  c  *  d 
b  c  *  d  e
c  *  
c  *  d  
c  *  d  e
*
*  d  
*  d  e







*/