class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<vector<int>> numOfOnes(n+1,vector<int>(32));
        for(int i=0;i<n;i++){
            int num=arr[i];
            numOfOnes[i+1]=numOfOnes[i];
            for(int j=0;j<32 && num>0;j++){
                if(num&1)
                    numOfOnes[i+1][j]++;
                num=num>>1;
            }
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1]+1;
            int subAns = INT_MAX;
            for(int j=0;j<32;j++){
                int countOfOnes = numOfOnes[end][j]-numOfOnes[start][j];
                if(countOfOnes%2==0){
                    subAns = subAns & (~(1<<j));
                } 
            }
            ans.push_back(subAns);
        }
        return ans;
    }
};