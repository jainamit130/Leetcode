class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> cache(word1.length()+1,vector<int>(word2.length()+1,INT_MAX));
        return solve(word1,word2,0,0,cache);
    }
    
    int solve(string& word1,string& word2,int i,int j,vector<vector<int>>& cache){
        if(i>=word1.length() && j>=word2.length()){
            return 0;
        }

        if(i>=word1.length()){
            return word2.length()-j;
        }

        if(j>=word2.length()){
            return word1.length()-i;
        }

        if(cache[i][j]!=INT_MAX){
            return cache[i][j];
        }

        int ans=INT_MAX;
        if(word1[i]==word2[j]){
            ans=min(ans,solve(word1,word2,i+1,j+1,cache));
        } else {
            ans=min(ans,1+solve(word1,word2,i,j+1,cache)); //insert
            ans=min(ans,1+solve(word1,word2,i+1,j,cache)); // delete
            ans=min(ans,1+solve(word1,word2,i+1,j+1,cache)); //replace
        }
        return cache[i][j]=ans;
    }
};

/*

1st Case => 
i,j++,operations++

2nd Case => 
i++,i,operations++

3rd Case => 
i++,j++,operations++



*/