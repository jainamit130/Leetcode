class Solution {
public:
    using pii = pair<int,int>;
    using ll = long long;
    set<pii> topX;
    set<pii> rem;
    unordered_map<int,int> freq;
    ll sum=0;
    vector<ll> findXSum(vector<int>& nums, int k, int x) {
        int j;
        for(j=0;j<k;j++){
            processSet(nums[j],true,x);
        }

        int i=0;
        vector<ll> ans;
        ans.push_back(sum);
        while(j<nums.size()){
            processSet(nums[i],false,x);
            i++;
            processSet(nums[j],true,x);
            j++;
            ans.push_back(sum);
        }
        return ans;
    }

    void processSet(int num,bool isInc,int x){
        if(topX.find({freq[num],num})!=topX.end()){
            sum-=(ll)num*freq[num];
        }
        topX.erase({freq[num],num});
        rem.erase({freq[num],num});

        if(isInc){
            freq[num]++;
        } else {
            freq[num]--;
        }

        if(freq[num]==0){
            freq.erase(num);
        }

        if(freq.find(num)!=freq.end()){
            topX.insert({freq[num],num});
            sum+=(ll)num*freq[num];
        }

        // Balance 
        // TopX = has elements greater than X
        // TopX = has elements smaller than X
        // TopX = has elements = to X

        if(topX.size()>x){
            auto [bottomFreq,bottomX] = *topX.begin();
            rem.insert({bottomFreq,bottomX});
            topX.erase({bottomFreq,bottomX});
            sum-=(ll)bottomX*bottomFreq;
        }

        if(topX.size()<x && !rem.empty()){
            auto [topRemFreq,topRem] = *rem.rbegin();
            rem.erase({topRemFreq,topRem});
            topX.insert({topRemFreq,topRem});
            sum+=(ll)topRemFreq*topRem;
        }

        if(topX.size()==x && !rem.empty()){
            auto [bottomXFreq,bottomX] = *topX.begin(); 
            auto [topRemFreq,topRem] = *rem.rbegin();
            if(bottomXFreq<topRemFreq || (bottomXFreq==topRemFreq && topRem>bottomX)){
                rem.erase({topRemFreq,topRem});
                topX.insert({topRemFreq,topRem});
                sum+=(ll)topRemFreq*topRem;
                rem.insert({bottomXFreq,bottomX});
                topX.erase({bottomXFreq,bottomX});
                sum-=(ll)bottomXFreq*bottomX;
            }
        }
    }
};


/*

if top of Rem = bot of topX (in terms of freq) => swap if the rem num > than topX num
if top of Rem != bot of topX (in terms of freq) => swap if the freq of rem num > freq of top num


unordered_map<int,int> freq
Set<pair<freq,num>> topX

Set<pair<freq,num>> rem


1   5   5   6   6   5

X=1
K=5

*/