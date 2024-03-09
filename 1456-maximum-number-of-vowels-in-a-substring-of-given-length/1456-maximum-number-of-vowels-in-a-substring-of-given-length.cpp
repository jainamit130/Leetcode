class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowels={'a','e','i','o','u'}; 
        int i=0;
        int j=0;
        int count=0;
        int maxCount=0; 
        while(j<s.length()){
            if(j-i+1<=k){
                if(vowels.find(s[j])!=vowels.end()){
                    count++;
                    maxCount=max(maxCount,count);
                }
                j++;
            } else {
                if(vowels.find(s[i])!=vowels.end()){
                    count--;
                } 
                if(vowels.find(s[j])!=vowels.end()){
                    count++;
                }
                maxCount=max(maxCount,count);
                j++;
                i++; 
            }
        }
        return maxCount;
    }
};