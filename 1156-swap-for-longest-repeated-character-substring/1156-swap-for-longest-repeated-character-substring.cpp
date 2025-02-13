class Solution {
public:
    int maxRepOpt1(string text) {
        if(text.size()==0) return 0;
        unordered_map<char,int> mp;
        vector<int> counts;
        string consolidatedStr = "";
        int count = 1;
        for(int i=1;i<=text.length();i++) {
            if(i<text.length() && text[i-1]==text[i]) {
                count++;
            } else {
                mp[text[i-1]]++;
                consolidatedStr+=text[i-1];
                counts.push_back(count);
                count = 1;
            }
        }
        // cout<<consolidatedStr<<endl;
        // for(auto n:counts){
        //     cout<<n;
        // }
        // cout<<endl;
        // for(auto [ch,count]:mp) {
        //     cout<<ch<<" -> "<<count<<endl;
        // }
        int ans = 0;
        int i = 0;
        int groupCount = counts.size();
        while(i<consolidatedStr.length()) {
            char firstCh = consolidatedStr[i];
            int firstCount = counts[i];
            ans = max({ans,firstCount});
            if(mp[firstCh]>1) {
                ans = max({ans,firstCount+1});
            }
            if(i+2>=consolidatedStr.length()){i++; continue;};
            char secondCh = consolidatedStr[i+1];
            int secondCount = counts[i+1];
            char thirdCh = consolidatedStr[i+2];
            int thirdCount = counts[i+2];
            if(thirdCh==firstCh) {
                if(secondCount==1) {
                    if(mp[firstCh]>2) {
                        ans = max(ans,firstCount+thirdCount+1);
                    } else {
                        ans = max(ans,firstCount+thirdCount);
                    }
                } else {
                    ans = max({ans,firstCount+1,thirdCount+1});
                }
            }
            groupCount--;
            i++;
        }
        return ans;
    }
};


/*

b   b   a   b   a   b   a   a   a   a



*/