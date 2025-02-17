class Solution {
public:
    vector<int> result;
    vector<int> constructDistancedSequence(int n) {
        int size = (n-1)*2+1;
        result.resize(size);
        vector<int> ans(size);
        vector<int> visited(n+1);
        result = max(ans,solve(n,visited,ans,0));
        return result;
    }

    vector<int> solve(int n,vector<int>& visited,vector<int>& ans,int index) {
        if(index>=ans.size()) {
            return ans;
        }
        
        if(ans[index]!=0) {
            result = max(result,solve(n,visited,ans,index+1));
        }

        bool flag = false;
        for(int i=1;i<=n;i++) {
            if(visited[i]==0) {
                if(i==1) {
                    ans[index]=1;
                    visited[i]=1;
                    result = max(result,solve(n,visited,ans,index+1));
                    visited[i]=0;
                    ans[index]=0;
                } else if(index+i<ans.size() && ans[index+i]==0) {
                    ans[index]=i;
                    ans[index+i]=i;
                    visited[i]=1;
                    result = max(result,solve(n,visited,ans,index+1));
                    visited[i]=0;
                    ans[index]=0;
                    ans[index+i]=0;
                }              
            }
        }
        return result;
    }
};