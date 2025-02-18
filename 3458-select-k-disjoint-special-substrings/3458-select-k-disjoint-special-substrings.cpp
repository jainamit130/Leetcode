class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        unordered_map<char,pair<int,int>> firstLastOcc;
        vector<pair<int,int>> intervals;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(firstLastOcc.find(s[i])==firstLastOcc.end()) {
                firstLastOcc[s[i]].first = i;    
            }
            firstLastOcc[s[i]].second = i;
        }

        for(char ch='a';ch<='z';ch++) {
            if(firstLastOcc.find(ch)==firstLastOcc.end()) continue;
            auto [firstIndex,lastIndex] = firstLastOcc[ch];
            if(lastIndex-firstIndex+1==n) continue;
            bool flag = true;
            int newLastIndex = lastIndex;
            for(int j=firstIndex;j<=lastIndex;j++) {
                if(firstLastOcc[s[j]].first<firstIndex) {
                    flag=false;
                    break;
                }
                newLastIndex = max(firstLastOcc[s[j]].second,newLastIndex);
            }
            if(newLastIndex-firstIndex+1<n && flag) {
                intervals.push_back({firstIndex,newLastIndex});
            }
        }

        sort(intervals.begin(),intervals.end(),[](auto lhs,auto rhs) {
            return lhs.second<rhs.second;
        });

        int ans = 0;
        int lastSelectedInterval = -1;
        for(int i=0;i<intervals.size();i++) {
            if(intervals[i].first>lastSelectedInterval) {
                ans++;
                lastSelectedInterval = intervals[i].second;
            }
        }
        return ans>=k;
    }
};

/*



*/