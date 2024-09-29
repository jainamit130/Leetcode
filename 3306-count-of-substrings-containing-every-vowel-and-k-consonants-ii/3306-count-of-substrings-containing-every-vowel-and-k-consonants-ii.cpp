class Solution {
public:
    unordered_map<char,int> vowelIndex = {{'a',0} , {'e',1} , {'i',2} , {'o',3} , {'u',4} };
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
            int firstVowelValidIndex = getValidIndex(word,i,vowelPrefix,0,k);
            int lastKValidIndex = getValidIndex(word,i,vowelPrefix,1,k);
            if(firstVowelValidIndex<=lastKValidIndex){
                ans+=(long long)lastKValidIndex-firstVowelValidIndex+1;
            }
        }
        return ans;
    }

    int getValidIndex(string word,int index,vector<vector<int>>& vowelPrefix,int choice,int k){
        int start=index;
        int end=word.length()-1;
        int ans=(choice==1)?start-1:word.length();
        while(start<=end){
            int mid = (start+end)/2;

            if(choice==0){
                bool valid=true;
                for(int i=0;i<5;i++){
                    if(vowelPrefix[mid+1][i]-vowelPrefix[index][i]==0){
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
k=1;
0   1   2   3   4   5   6   7   8   9   10  11  12  13
i   e   a   o   u   q   q   i   e   a   o   u   q   q
0   0   0   0   0   1   2   2   2   2   2   2   3   4





*/