class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        unordered_map<char,pair<int,int>> firstLastOcc;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(firstLastOcc.find(s[i])==firstLastOcc.end()) firstLastOcc[s[i]] = {i,i};
            firstLastOcc[s[i]].second=i;
        }

        vector<pair<int,int>> intervals;
        for(char ch='a';ch<='z';ch++) {
            if(firstLastOcc.find(ch)==firstLastOcc.end()) continue;
            auto [firstIndex,lastIndex] = firstLastOcc[ch];
            bool flag = true;
            for(int i=firstIndex;i<=lastIndex;i++) {
                if(firstLastOcc.find(s[i])==firstLastOcc.end()) continue;
                if(firstLastOcc[s[i]].first<firstIndex) {
                    flag = false;
                    break;
                } else {
                    lastIndex = max(lastIndex,firstLastOcc[s[i]].second);
                }
            }

            if(lastIndex-firstIndex+1<n && flag) {
                intervals.push_back({firstIndex,lastIndex});
            }
        }

        sort(intervals.begin(),intervals.end(),[](auto lhs,auto rhs) {
            return lhs.second<rhs.second;
        });
        int ans = 0;
        int lastSelectedInterval = -1;
        for(auto interval:intervals) {
            if(interval.first>lastSelectedInterval) {
                ans++;
                lastSelectedInterval=interval.second;
            }
        }
        return ans>=k;
    }
};


/*
0   1   2   3   4   5   6   7   8   9
a   b   c   d   b   a   e   f   a   b


first and last occur

a -> 0,8
b -> 1,9
c -> 2,2
...

iterate through every alphabet if in map of occurences

ex: a -> first index, last index -> iteratre through first index -> last index and see if any character inside has the first occurence before firstIndex or lastOccurence after lastIndex if not then push it inside valid intervals 

valid groups

0   8
1   9
2   2
3   3
6   6
7   7


sort these intervals based on ending index and consider taking every first end interval
keep a count by the end if our count>=k


*/