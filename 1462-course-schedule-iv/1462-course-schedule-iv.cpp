//Topological Sort

//BFS
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<bool> result(queries.size());
        //Constructing Adjacency List
        for(int i=0;i<prerequisites.size();i++)
            adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        //Topological Sort
        unordered_map<int,unordered_set<int>> prereqMap;
        for(int i=0;i<numCourses;i++)
            bfs(adjacencyList,i,prereqMap);

        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int dst=queries[i][1];
            result[i]=prereqMap[start].find(dst)!=prereqMap[start].end();
        }
        return result;
    }

    void bfs(vector<vector<int>>& adj,int course,unordered_map<int,unordered_set<int>>& prereqMap){
        queue<int> q;
        q.push(course);
        while(!q.empty()){
            int size=q.size();
            while(size){
                int top=q.front();
                q.pop();
                size--;
                if(prereqMap[course].find(top)!=prereqMap[course].end())
                    continue;
                prereqMap[course].insert(top);
                for(int i=0;i<adj[top].size();i++){
                    if(prereqMap[course].find(adj[top][i])==prereqMap[course].end())
                        q.push(adj[top][i]);
                }
            }
        }
        return;
    }
};

//DFS
// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> adjacencyList(numCourses);
//         vector<bool> result(queries.size());
//         //Constructing Adjacency List
//         for(int i=0;i<prerequisites.size();i++)
//             adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
//         //Topological Sort
//         unordered_map<int,unordered_set<int>> prereqMap;
//         for(int i=0;i<numCourses;i++)
//             dfs(adjacencyList,i,prereqMap);

//         for(int i=0;i<queries.size();i++){
//             int start=queries[i][0];
//             int dst=queries[i][1];
//             result[i]=prereqMap[start].find(dst)!=prereqMap[start].end();
//         }
//         return result;
//     }

//     unordered_set<int> dfs(vector<vector<int>>& adj,int course,unordered_map<int,unordered_set<int>>& prereqMap){
//         if(prereqMap.find(course)!=prereqMap.end())
//             return prereqMap[course];

//         unordered_set<int> topoSet;
//         for(int i=0;i<adj[course].size();i++){
//             unordered_set<int> temp=dfs(adj,adj[course][i],prereqMap);
//             prereqMap[course].insert(temp.begin(),temp.end());
//         }
//         prereqMap[course].insert(course);
//         return prereqMap[course];
//     }
// };

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