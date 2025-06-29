class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<words.size()-1;i++) {
            pq.push({getCommonPrefix(words[i],words[i+1]),i});
            if(pq.size()>2) pq.pop();
        }
        int secondMax = 0; int secondIndex = -2;
        int maxi = 0; int maxIndex = -2;
        vector<int> ans;
        if(pq.size()==2) {
            secondMax = pq.top()[0];
            secondIndex=pq.top()[1];
            pq.pop();
        }

        if(pq.size()==1) {
            maxi = pq.top()[0];
            maxIndex=pq.top()[1];
            pq.pop();
        }
        for(int i=0;i<words.size();i++) {
            int subAns = 0;
            if(i!=maxIndex && i!=maxIndex+1) {
                subAns = maxi;
            } else if(i!=secondIndex && i!=secondIndex+1) {
                subAns = secondMax;
            }

            if(i>0 && i+1<words.size()) {
                subAns = max(subAns,getCommonPrefix(words[i-1],words[i+1]));
            }

            ans.push_back(subAns);
        }
        return ans;
    }

    int getCommonPrefix(string& word1,string& word2) {
        int j = 0;
        while(j<word1.length() && j<word2.length()) {
            if(word1[j]==word2[j]) {
                j++;
            } else break;
        }
        return j;
    }
};

/*

Steps:


1. precompute the max and second max along with the respective first index of the pair
2. iterate the array and compute the prev and next word common prefix get the valid contribution



*/