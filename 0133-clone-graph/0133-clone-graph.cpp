/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<int,Node*> mp;
        queue<pair<Node*,Node*>> q;
        Node* ans = new Node(node->val);
        mp[ans->val]=ans;
        q.push({ans,node});
        while(!q.empty()) {
            auto [node,realNode] = q.front();
            q.pop();
            for(auto neigh:realNode->neighbors) {
                if(mp.find(neigh->val)!=mp.end()){ 
                    node->neighbors.push_back(mp[neigh->val]);    
                    continue;
                }
                mp[neigh->val]=new Node(neigh->val);
                node->neighbors.push_back(mp[neigh->val]);
                q.push({mp[neigh->val],neigh});
            }
        }
        return ans;
    }
};


/*

given
=> Node => val(int); List<Node> (this can be empty)
=> graph is connected and undirected
=> given node is always the first node with val 1

Conclusion => no scene of empty List<Node> neighbors becuase undirected and connected graph


Approach
1. to start a bfs from the given 1st node
2. recursively create a clone 
3. base case would be 

1 - 2 - 8 

1 -> 2,8
8 -> 1,2
2 -> 1,8

*/