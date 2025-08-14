class Solution {
public:
    unordered_map<int, int> mapping;
    int allowed;

    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> black(blacklist.begin(), blacklist.end());
        allowed = n - blacklist.size();
        int last = n - 1;

        for (int b : blacklist) {
            if (b < allowed) {
                while (black.count(last)) last--;
                mapping[b] = last--;
            }
        }

    }

    int pick() {
        int r = rand() % allowed;
        return mapping.count(r) ? mapping[r] : r;
    }
};



// class Solution {
// public:
//     map<int,int> mp;
//     int n;
//     Solution(int m, vector<int>& blacklist) {
//         n = m;
//         sort(blacklist.begin(),blacklist.end());
//         int last = -1;
//         int count = 1;
//         mp[-1]=-1;
//         for(int i=0;i<=blacklist.size();i++) {
//             if(i<blacklist.size() && blacklist[i]==last+count) {
//                 count++;
//                 continue;
//             } else {
//                 if((last!=-1 && i==0) || i>0) mp[last] = blacklist[i-1];
//                 if(i<blacklist.size()) last = blacklist[i];
//                 else break;
//                 count = 1;
//             }
//         }
//         if(mp.rbegin()->second!=n-1) mp[n]=n;
//         else mp[n-count]=n;
//         for(auto [x,y]:mp) cout<<x<<" "<<y<<endl;
//     }
    
//     int pick() {
//         int element = rand()%n;
//         cout<<element<<endl;
//         auto itr = mp.lower_bound(element);
//         int start = 0;
//         int end = n-1;
//         if(itr!=mp.end()) {
//             start = itr->second+1;
//             if(itr!=mp.begin() && rand()%2) {
//                 end = itr->first-1;
//                 itr--;
//                 start=itr->second+1;
//                 return rand()%(end-start+1) + start;
//             }
//             itr++;
//             if(itr!=mp.end()) end = itr->first-1;
//             else {
//                 itr--;
//                 end = itr->first-1;
//                 itr--;
//                 start=itr->second+1;
//             }
//         } else {
//             itr--;
//             end = itr->first-1;
//             itr--;
//             start=itr->second+1;
//         }
//         return rand()%(end-start+1) + start;
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */