class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> prefixFreq;
        vector<int> toSearch(26);
        prefixFreq.push_back(toSearch);
        for(auto n:word1){
            prefixFreq.push_back(prefixFreq.back());
            prefixFreq.back()[n-'a']++;
        }
        for(auto n:word2){
            toSearch[n-'a']++;
        }

        long long ans=0;
        for(int i=0;i<m;i++){
            ans+=m-binarySearch(toSearch,prefixFreq,i,m-1);
            toSearch[word1[i]-'a']++;
        }
        return ans;
    }

    int binarySearch(vector<int>& toSearch,vector<vector<int>>& prefixFreq,int start,int end){
        int ans = end+1;
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(toSearch,prefixFreq[mid+1])){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        return ans;
    }

    bool isValid(vector<int>& toSearch,vector<int>& prefix){
        for(int i=0;i<26;i++){
            if(toSearch[i]>prefix[i]){
                return false;
            }
        }
        return true;
    }
};


/*

a   1
b   1
c   1

        5-2+1 =4
        5-3+1 =3
        5-2+1 =2 
        5-5+1 =1
-------------------
                10

        0   1   2   3   4   5
        a   b   c   a   b   c

a   0   1   1   1   2   2   2
b   0   0   1   1   1   2   2 
c   0   0   0   1   1   1   2


*/


