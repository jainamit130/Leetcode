class Solution {
public:
    unordered_map<char,int> vowelIndex = { {'a',0}, {'e',1},{'o',2},{'i',3},{'u',4} };
    long long countOfSubstrings(string word, int k) {
        int n=word.length();
        vector<vector<int>> vowelPrefix(n+1,vector<int>(6));

        for(int i=0;i<n;i++){
            vowelPrefix[i+1]=vowelPrefix[i];
            if(vowelIndex.find(word[i])!=vowelIndex.end()){
                vowelPrefix[i+1][vowelIndex[word[i]]]++;
                vowelPrefix[i+1][5]++;
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            int start=binarySearch(i,vowelPrefix,k,0);
            int end=binarySearch(i,vowelPrefix,k,1);
            if(start<=end){
                ans+=(long long)end-start+1;
            }
        }
        return ans;
    }

    int binarySearch(int index,vector<vector<int>>& vowelPrefix,int k,int choice){
        int n=vowelPrefix.size()-1;
        int start=index;
        int end=n-1;
        int ans=(choice==0)?n:start-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(choice==0){
                bool valid=true;
                for(int i=0;i<5;i++){
                    int vowelCount = vowelPrefix[mid+1][i]-vowelPrefix[index][i];
                    if(vowelCount==0){
                        valid=false;
                        break;
                    }
                }
                int consonentCount = mid-index+1-(vowelPrefix[mid+1][5]-vowelPrefix[index][5]);
                if(valid && consonentCount>=k){
                    ans=mid;
                    end=mid-1;
                } else {
                    start=mid+1;
                }
            } else {
                int consonentCount = mid-index+1-(vowelPrefix[mid+1][5]-vowelPrefix[index][5]);
                if(consonentCount<=k){
                    ans=mid;
                    start=mid+1;
                } else {
                    end=mid-1;
                }
            }
        }
        return ans;
    }
};


/*

consonentCount = total Char - totalVowels 

BS1: vowelCondition + consonentCount>=k
BS2: consonentCount<=k



*/