class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int ans=0;
        int last=0;
        for(int i=k;i<word.length();i++){
            if(abs(word[i]-word[i-1])>2){
                ans+=solve(last,i-1,word,k);
                last=i;
            }
        }
        ans+=solve(last,word.length()-last-1,word,k);
        return ans;
    }

    int solve(int start,int end,string& word,int k){
        int subAns=0;
        for(int uniqueCh = 1; uniqueCh<=26 && uniqueCh*k<=end-start+1;uniqueCh++){
            int ws = uniqueCh*k;
            vector<int> count(26);
            int i=start;
            int good=0;
            for(int j=start;j<=end;j++){
                char ch = word[j];
                count[ch-'a']++;
                if(count[ch-'a']==k)
                    good++;
                else if(count[ch-'a']==k+1)
                    good--;

                if(j-i+1>ws){
                    if(count[word[i]-'a']==k+1)
                        good++;
                    else if(count[word[i]-'a']==k)
                        good--;
                    count[word[i]-'a']--;
                    i++;
                }
                if(good==uniqueCh)
                    subAns++;
            }
        }
        return subAns;
    }
};



/*

i   g   i   g   e   e
                i   j

ans = 3

map
e -> 2

*/