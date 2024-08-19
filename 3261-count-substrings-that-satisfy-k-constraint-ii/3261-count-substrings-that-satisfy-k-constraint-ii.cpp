class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int> right(n);
        vector<int> left(n);
        int i=0,j=0;
        unordered_map<char,int> mp;
        //Populating left
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp['1']>k && mp['0']>k){
                mp[s[i]]--;
                i++;
            }
            left[j]=i;
            j++;
        }
        mp.clear();
        i=n-1,j=n-1;
        while(j>=0){
            mp[s[j]]++;
            while(i>j && mp['1']>k && mp['0']>k){
                mp[s[i]]--;
                i--;
            }
            right[j]=i;
            j--;
        }
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[i]=i-left[i]+1;
        }
        vector<long long> prefix;
        prefix.push_back(0);
        for(auto t:temp){
            prefix.push_back(prefix.back()+t);
        }
        vector<long long> ans;
        for(int i=0;i<queries.size();i++){
            int low=queries[i][0];
            int high=queries[i][1];
            int validIndex=min(high,right[low]);
            int size=validIndex-low+1;
            long long res=(long long)(size)*(size+1)/2;
            long long add=prefix[high+1]-prefix[validIndex+1];
            res+=add;
            ans.push_back(res);
        }
        return ans;
    }
};