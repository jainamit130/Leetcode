class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> A,B;
        for(int i=0;i<graph[0].size();i++){
            B.insert(graph[0][i]);
        }
        if(graph[0].size()==0){
            return false;
        }
        for(int i=0;i<graph[graph[0][0]].size();i++){
            int element=graph[graph[0][0]][i];
            if(B.find(element)!=B.end()){
                return false;
            }
            A.insert(element);
        }

        for(int i=0;i<graph.size();i++){
            int turn=0;
            if(A.find(i)==A.end()){
                if(B.find(i)==B.end()){
                    return false;
                }
                turn=1;
            } 
            for(int j=0;j<graph[i].size();j++){
                int element=graph[i][j];
                if(A.find(element)==A.end()){
                    if(B.find(element)==B.end()){
                        return false;
                    } else {
                        if(turn==1)
                            return false;
                    }
                } else {
                    if(turn==0)
                        return false; 
                }
            }
        }
        return true;
    }
};