class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> prefixFreq(m+1,vector<int>(26));
        for(int i=0;i<m;i++){
            prefixFreq[i+1]=prefixFreq[i];
            prefixFreq[i+1][word1[i]-'a']++;
        }

        long long ans=0;
        for(int i=0;i<m;i++){
            vector<int> toSearch=prefixFreq[i];
            for(int j=0;j<n;j++){
                toSearch[word2[j]-'a']++;
            }
            ans+=m-binarySearch(toSearch,i,prefixFreq,m);
        }
        return ans;
    }

    int binarySearch(vector<int>& toSearch,int start,vector<vector<int>>& prefix,int m){
        int end = prefix.size()-2;
        int ans=m;
        while(start<=end){
            int mid = (start+end)/2;
            if(isValid(prefix[mid+1],toSearch)){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        return ans;
    }

    bool isValid(vector<int>& prefix,vector<int>& toSearch){
        for(int i=0;i<26;i++){
            if(prefix[i]<toSearch[i]){
                return false;
            }
        }
        return true;
    }
};

/*

    a   b   c   a   b   c

a   1   1   1   2   2   2
b   0   1   1   1   2   2 
c   0   0   1   1   1   2


*/