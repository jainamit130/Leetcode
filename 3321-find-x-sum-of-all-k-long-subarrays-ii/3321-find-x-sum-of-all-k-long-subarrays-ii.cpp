class Solution {
public:
    using pii=pair<int,int>;
    using ll = long long;
    vector<ll> findXSum(vector<int>& nums, int k, int x) {
        set<pii> topX;
        set<pii> rem;
        unordered_map<int,int> freq;
        ll sum = 0;
        int j;
        for(j=0;j<k;j++){
            processSet(topX,rem,freq,nums[j],sum,true,x);
        }
        int i=0;
        vector<ll> ans;
        ans.push_back(sum);
        while(j<nums.size()){
            processSet(topX,rem,freq,nums[i],sum,false,x);
            i++;
            processSet(topX,rem,freq,nums[j],sum,true,x);
            j++;
            ans.push_back(sum);
        }
        return ans;
    }

    void processSet(set<pii>& topX,set<pii>& rem,unordered_map<int,int>& freq,int num,ll& sum,bool isInc,int x){
        if(topX.find({freq[num],num})!=topX.end()){
            sum-=(ll)1*freq[num]*num;
        }
        topX.erase({freq[num],num});
        rem.erase({freq[num],num});

        if(isInc)  
            freq[num]++;
        else
            freq[num]--;
        if(freq[num]==0){
            freq.erase(num);
        }
        if(freq.find(num)!=freq.end()) {
            topX.insert({freq[num],num});
            sum+=(ll)1*freq[num]*num;
        }

        if(topX.size()==x && !rem.empty()){
            auto [bottomXFreq,bottomX] = *topX.begin();
            auto [topRemFreq, topRem] = *rem.rbegin();
            if(bottomXFreq<topRemFreq || (bottomXFreq==topRemFreq && topRem>bottomX)){
                topX.erase({bottomXFreq,bottomX});
                sum-=(ll)1*bottomXFreq*bottomX;
                topX.insert({topRemFreq, topRem});
                sum+=(ll)1*topRemFreq*topRem;
                rem.erase({topRemFreq, topRem});
                rem.insert({bottomXFreq,bottomX});
            }
        }

        if(topX.size()>x){
            auto [bottomXFreq,bottomX] = *topX.begin();
            rem.insert({bottomXFreq,bottomX});
            topX.erase({bottomXFreq,bottomX});
            sum-=(ll)1*bottomXFreq*bottomX;
        }

        if (topX.size() < x && !rem.empty()) {
            auto [topRemFreq, topRem] = *rem.rbegin();
            topX.insert({topRemFreq, topRem});
            rem.erase({topRemFreq, topRem});
            sum += (ll)1*topRemFreq * topRem;
        }
    }
};