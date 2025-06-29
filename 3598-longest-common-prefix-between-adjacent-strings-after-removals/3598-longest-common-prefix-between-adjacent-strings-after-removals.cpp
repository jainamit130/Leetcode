class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<words.size()-1;i++) {
            pq.push({getCommonPrefix(words[i],words[i+1]),i});
            if(pq.size()>2) pq.pop();
        }

        vector<int> ans;
        int secondMax = 0;
        int b = -2;
        int maxi = 0;
        int a = -2;
        if(pq.size()==2) {
            secondMax = pq.top()[0];
            b = pq.top()[1];
            pq.pop();
        } 
        if(pq.size()==1) {
            maxi = pq.top()[0];
            a = pq.top()[1];
            pq.pop();
        }
        for(int i=0;i<words.size();i++) {
            int subAns = 0;
            if(i!=a && i!=a+1) {
                subAns = maxi;
            } else if(i!=b && i!=b+1){
                subAns = secondMax;
            }
            if(i>0 && i+1<words.size()) {
                // find prefix between i-1 and i+1
                subAns = max(subAns,getCommonPrefix(words[i-1],words[i+1]));
            } 
            ans.push_back(subAns);
        }
        return ans;
    }

    int getCommonPrefix(string word1,string word2) {
        int j = 0;
        int k = 0;
        while(j<word1.length() && k<word2.length()) {
            if(word1[j]==word2[j]) {
                k++;j++;
            } else {
                break;
            }
        }
        return k;
    }
};


/*


jump run run jump run
0    3   0   0



*/