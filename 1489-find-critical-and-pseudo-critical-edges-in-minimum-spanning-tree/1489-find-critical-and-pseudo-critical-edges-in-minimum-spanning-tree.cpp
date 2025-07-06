class UnionNode {
    public:
        vector<int> parent;
        vector<int> rank;
        UnionNode(int n) {
            rank.resize(n);
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
        }

        int findParent(int node) {
            if (parent[node] != node) {
                parent[node] = findParent(parent[node]);
            }
            return parent[node];
        }


        bool merge(int node1,int node2) {
            int parent1 = findParent(node1);
            int parent2 = findParent(node2);
            if(parent1==parent2) return false;
            if(rank[parent1]>=rank[parent2]) {
                rank[parent1]++;
                parent[parent2] = parent1;
            } else {
                rank[parent2]++;
                parent[parent1] = parent2;
            }
            return true;
        }
};


/*

MST without a edge 

0 -> -1
1 -> -1
2 -> 7
3 -> 7
4 -> 7
5 -> 6


*/

class Solution {
public:
    int minMst = INT_MAX;
    int m;
    int nodeCount;
    vector<int> indexEdges;
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        m = edges.size();
        nodeCount = n;
        indexEdges.resize(m);
        iota(indexEdges.begin(),indexEdges.end(),0);
        sort(indexEdges.begin(),indexEdges.end(),[&](auto& lhs,auto& rhs){
            return edges[lhs][2]<edges[rhs][2];
        });
        vector<int> mstWithEdge(m,INT_MAX);
        vector<int> mstWithoutEdge(m,INT_MAX);
        for(int i=0;i<m;i++) {
            // find mst wihtout this edge
            UnionNode* root = new UnionNode(n);
            mstWithoutEdge[indexEdges[i]] = getMst(root,edges,i,0,0);
            
            // find mst with this edge
            root = new UnionNode(n);
            root->merge(edges[indexEdges[i]][0],edges[indexEdges[i]][1]);
            mstWithEdge[indexEdges[i]] = getMst(root,edges,i,1,edges[indexEdges[i]][2]);
        }

        vector<int> critical;
        vector<int> pseudoCritical; 
        for(int i=0;i<m;i++) {
            if(mstWithoutEdge[i]>minMst) critical.push_back(i);
            else if(mstWithEdge[i]==minMst) pseudoCritical.push_back(i);  
        }
        return {critical,pseudoCritical};
    }

    int getMst(UnionNode* root,vector<vector<int>>& edges,int indexToIgnore,int edgesCount,int weight) {
        for(int i=0;i<m;i++) {
            int index = indexEdges[i];
            if(indexToIgnore==i) continue;
            if(root->merge(edges[index][0],edges[index][1])) {
                edgesCount++;
                weight+=edges[index][2];
            }
        }
        if(edgesCount!=(nodeCount-1)) return INT_MAX; 
        minMst = min(weight,minMst);
        return weight;
    }
};

// class Solution {
// public:
//     int minWt = INT_MAX;
//     int mstCount = 0;
//     int m;
//     int k;
//     vector<int> contributions;
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         m = edges.size();
//         k = n;
//         contributions.resize(m);
//         UnionNode* root = new UnionNode(n);
//         vector<int> currContributions = contributions;
//         solve(edges,0,currContributions,0,0,root);
//         vector<int> critical;
//         vector<int> pseudoCritical;
//         for(int i=0;i<m;i++) {
//             if(contributions[i]==0) continue;
//             if(contributions[i]==mstCount) critical.push_back(i);
//             else pseudoCritical.push_back(i);
//         }
//         return {critical,pseudoCritical};
//     }

//     void solve(vector<vector<int>>& edges,int index,vector<int> currContributions,int edgesCount,int currWt,UnionNode* root) {
//         if(index>=m) {
//             if(edgesCount!=k-1) return;
//             if(currWt<minWt) {
//                 minWt=currWt;
//                 mstCount = 1;
//                 contributions = currContributions;
//             } else if(currWt == minWt) {
//                 mstCount++;
//                 for(int i=0;i<m;i++) {
//                     contributions[i] += currContributions[i];
//                 }
//             }
//             return;
//         }
//         int oldP1 = root->parent[edges[index][0]];
//         int oldRank1 = root->rank[edges[index][0]];
//         int oldP2 = root->parent[edges[index][1]];
//         int oldRank2 = root->rank[edges[index][1]];
//         if(root->merge(edges[index][0],edges[index][1])) {
//             currContributions[index]++;
//             solve(edges,index+1,currContributions,edgesCount+1,currWt+edges[index][2],root);
//             currContributions[index]--;
//             root->parent[edges[index][0]] = oldP1;
//             root->rank[edges[index][0]] = oldRank1;

//             root->parent[edges[index][1]] = oldP2;
//             root->rank[edges[index][1]] = oldRank2;
//         } 
//         solve(edges,index+1,currContributions,edgesCount,currWt,root);
//         return;
//     }
// };