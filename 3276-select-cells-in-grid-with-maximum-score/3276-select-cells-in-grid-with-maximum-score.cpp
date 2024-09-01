class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        unordered_map<int,unordered_set<int>> num_rows; // Each values belongs to which all rows
        set<int> uniqueNumsSet; // Sorted Unique Numbers
        vector<int> uniqueNums;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                uniqueNumsSet.insert(grid[i][j]);
                num_rows[grid[i][j]].insert(i);
            }
        }
        
        for(auto itr=uniqueNumsSet.rbegin();itr!=uniqueNumsSet.rend();itr++){
            uniqueNums.push_back(*itr);
        }
        unordered_set<int> usedRows;
        return solve(uniqueNums,num_rows,m,0,usedRows);
    }

    int solve(vector<int>& nums,unordered_map<int,unordered_set<int>>& num_rows,int m,int index,unordered_set<int>& usedRows){
        if(index>=nums.size() || num_rows.size()==m){
            return 0;
        }
        int ans=0;
        bool flag=0;
        for(auto row:num_rows[nums[index]]){
            if(usedRows.find(row)!=usedRows.end()){
                continue;
            }
            flag=1;
            usedRows.insert(row);
            ans=max(ans,nums[index]+solve(nums,num_rows,m,index+1,usedRows));
            usedRows.erase(row);
        }
        if(flag==0){
            ans=max(ans,solve(nums,num_rows,m,index+1,usedRows));
        }
        return ans;
    }
};



/*


2   3   6   7   8   8
1   1   0   0   1   0

*/