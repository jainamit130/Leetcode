//Topological Sort

//DFS
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<bool> result(queries.size());
        //Constructing Adjacency List
        for(int i=0;i<prerequisites.size();i++)
            adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        //Topological Sort
        unordered_map<int,int> mp;
        vector<int> topoSort;
        vector<bool> visited(numCourses);
        for(int i=0;i<numCourses;i++){
            dfs(adjacencyList,i,visited,topoSort);
        }
        reverse(topoSort.begin(),topoSort.end());
        for(int i=0;i<topoSort.size();i++)
            mp[topoSort[i]]=i;
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int dst=queries[i][1];
            cout<<mp[start]<<" "<<mp[dst]<<endl;
            result[i]=mp[start]<mp[dst]?true:false;
        }
        return result;
    }

    void dfs(vector<vector<int>>& adj,int course,vector<bool>& visited,vector<int>& topoSort){
        if(visited[course])
            return;

        visited[course]=true;
        //traversing all neighbours
        for(int i=0;i<adj[course].size();i++){
            dfs(adj,adj[course][i],visited,topoSort);
        }

        topoSort.push_back(course);
        return;
    }
};

//Brute Force

//BFS
// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> adjacencyList(numCourses);
//         vector<bool> result(queries.size());
//         //Constructing Adjacency List
//         for(int i=0;i<prerequisites.size();i++)
//             adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
  
//         for(int i=0;i<queries.size();i++){
//             int start=queries[i][0];
//             int dst=queries[i][1];
//             result[i]=bfs(adjacencyList,start,dst,numCourses);
//         }
//         return result;
//     }

//     bool bfs(vector<vector<int>>& adj,int start,int dst,int numCourses){
//         queue<int> q;
//         vector<bool> visited(numCourses);
//         q.push(start);
//         while(!q.empty()){
//             int size=q.size();
//             while(size){
//                 int top=q.front();
//                 if(top==dst)
//                     return true;
//                 q.pop();
//                 size--;
//                 if(visited[top])
//                     continue;
//                 visited[top]=true;
//                 for(int i=0;i<adj[top].size();i++){
//                     if(!visited[adj[top][i]])
//                         q.push(adj[top][i]);
//                 }
//             }
//         }
//         return false;
//     }
// };

//DFS
// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> adjacencyList(numCourses);
//         vector<bool> result(queries.size());
//         //Constructing Adjacency List
//         for(int i=0;i<prerequisites.size();i++)
//             adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
  
//         for(int i=0;i<queries.size();i++){
//             int start=queries[i][0];
//             int dst=queries[i][1];
//             vector<bool> visited(numCourses);
//             result[i]=dfs(adjacencyList,start,dst,visited);
//         }
//         return result;
//     }

//     bool dfs(vector<vector<int>>& adj,int start,int dst,vector<bool>& visited){
//         if(visited[start])
//             return false;

//         if(start==dst)
//             return true;

//         visited[start]=true;
//         bool ans=false;
//         for(int i=0;i<adj[start].size();i++){
//             ans=ans || dfs(adj,adj[start][i],dst,visited);
//         }
//         return ans;
//     }
// };