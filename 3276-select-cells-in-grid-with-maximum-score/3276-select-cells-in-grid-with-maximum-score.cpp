class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        unordered_map<int,unordered_set<int>> num_rows; // Rows of each unique val
        set<int> uniqueNumSet;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                uniqueNumSet.insert(grid[i][j]);
                num_rows[grid[i][j]].insert(i);
            }
        }

        vector<int> uniqueNums;
        for(auto itr=uniqueNumSet.rbegin();itr!=uniqueNumSet.rend();itr++){
            uniqueNums.push_back(*itr);
        }
        unordered_set<int> usedRows;
        return solve(uniqueNums,num_rows,0,usedRows,m);
    }

    int solve(vector<int>& nums,unordered_map<int,unordered_set<int>>& num_rows,int index,unordered_set<int>& usedRows,int m){
        if(index>=nums.size() || usedRows.size()==m){
            return 0;
        }

        int ans=0;
        int flag=0;
        for(auto rows:num_rows[nums[index]]){
            if(usedRows.find(rows)==usedRows.end()){
                usedRows.insert(rows);
                flag=1;
                ans=max(ans,nums[index]+solve(nums,num_rows,index+1,usedRows,m));
                usedRows.erase(rows);
            }
        }
        if(flag==0){
            ans=max(ans,solve(nums,num_rows,index+1,usedRows,m));
        }
        return ans;
    }
};

/*

5 -> 0,1

nums= {5}

0 =>5   5   5
1 =>5   5   5


*/

/*

usedValues Set and row


*/