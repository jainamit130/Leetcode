/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        vector<Employee*> adj(2001);
        for(int i=0;i<employees.size();i++){
            adj[employees[i]->id]=employees[i];
        }

        return solve(adj,id);
    }

    int solve(vector<Employee*> adj,int id){
        if(adj[id]->subordinates.size()==0){
            cout<<id<<endl;
            return adj[id]->importance;
        }
        int ans=adj[id]->importance;
        for(int i=0;i<adj[id]->subordinates.size();i++){
            ans+=solve(adj,adj[id]->subordinates[i]);
        }
        return ans;
    }
};