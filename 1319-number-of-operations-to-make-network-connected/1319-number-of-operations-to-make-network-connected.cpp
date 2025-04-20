class UnionNode {
    public:
        vector<int> parents;
        vector<int> ranks;
        UnionNode(int n) {
            ranks.resize(n);
            for(int i=0;i<n;i++) {
                parents.push_back(i);
            }
        }

        int findParent(int node) {
            int parent = parents[node];
            while(parent!=parents[parent]) {
                parent = findParent(findParent(parent));
            }
            return parent;
        }

        bool merge(int n1,int n2) {
            int p1 = findParent(n1);
            int p2 = findParent(n2);
            if(p1==p2) return false;
            if(ranks[p1]>ranks[p2]) {
                parents[p2]=p1;
                ranks[p1]++;
            } else {
                parents[p1]=p2;
                ranks[p2]++;
            }
            return true;
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        
        UnionNode* root = new UnionNode(n);
        for(auto edge:connections) {
            int n1 = edge[0];
            int n2 = edge[1];
            root->merge(n1,n2);
        }
        
        int ans = 0;
        int parent = root->findParent(0);
        for(int i=1;i<n;i++) {
            if(root->merge(parent,i)) ans++;
        }
        return ans;
    }
};



/*
Clarifications:

1. Given: vector<vector<int>> connections => Format : [ai,bi] => meaning they have undirected edges; int n => n is a +ve integer it cant be 0
2. in connections [ai,bi]; here ai and bi are always between 0 -> n-1? yes
3. Return int => min number of operations (taking a edge and placing between 2 nodes which are not connected)
4. No Parallel edges? yes
5. No self edges? yes

Goal: 1. Pick a edge which is already connected with out without that edge
      2. Place the edge between 2 nodes which are not connected directly or indirectly

Conclusions=>
1. Negative/Bad case => if the count of total edges is < N-1 then not possible return -1
2. Goal 1 can be ignored because i dont really need the graph as the return value so it does not matter from where i pick the edge.
2. Goal 2 matters because i need to place it appropriately

Approach: (Union Find)
1. Check for the negative case => Checking the size of connections array => size of connections array>=N-1 
2. Initialize the ans = 0 and a Union Find Data structure.
3. Iterate the edges and try to merge them
    i. If already part of same group then continue;
    ii. If not then merge them and increment the ans once 

Time Complexity => Ackermann Function => O(alpha * n) ~ O(1) for every merge (Given that we use path compression in finding the or the parent of a node) => O(2*(alpha*n)*n)

Space Complexity => O(2*n)



*/