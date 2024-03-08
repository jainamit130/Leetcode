class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<bool> result(queries.size());
        //Constructing Adjacency List
        for(int i=0;i<prerequisites.size();i++)
            adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
  
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int dst=queries[i][1];
            set<int> visited;
            result[i]=dfs(adjacencyList,start,dst,visited);
        }
        return result;
    }

    bool dfs(vector<vector<int>>& adj,int start,int dst,set<int>& visited){
        if(visited.find(start)!=visited.end())
            return false;

        if(start==dst)
            return true;

        visited.insert(start);
        bool ans=false;
        for(int i=0;i<adj[start].size();i++){
            ans=ans || dfs(adj,adj[start][i],dst,visited);
        }
        return ans;
    }
};