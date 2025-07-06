class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adjacencyList;
        for(int i=0;i<equations.size();i++){
            adjacencyList[equations[i][0]].push_back({equations[i][1],values[i]});
            adjacencyList[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> result;
        set<string> visited; 
        for(int i=0;i<queries.size();i++){
            double ans=-1.0;
            double product=1.0;
            unordered_set<string> visited;
            if(adjacencyList.find(queries[i][0])!=adjacencyList.end())
                dfs(adjacencyList,queries[i][0],queries[i][1],product,visited,ans);
            result.push_back(ans);  
        }
        return result;
    }

    void dfs(unordered_map<string,vector<pair<string,double>>>& adjacencyList,string src,string dst,double product,unordered_set<string> visited,double& ans){
        if(visited.find(src)!=visited.end())
            return;

        visited.insert(src);

        if(src==dst){
            ans=product;
            return;
        }

        for(int i=0;i<adjacencyList[src].size();i++)
            dfs(adjacencyList,adjacencyList[src][i].first,dst,product*adjacencyList[src][i].second,visited,ans);
        return;
    }
};