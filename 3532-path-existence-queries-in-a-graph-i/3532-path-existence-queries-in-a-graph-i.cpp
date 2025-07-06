class UnionNode {
    public:
        vector<int> parent;
        vector<int> rank;
        UnionNode(int n) {
            parent.resize(n);
            rank.resize(n);
            iota(parent.begin(),parent.end(),0);
        }

        int findParent(int n) {
            while(parent[n]!=n) {
                n = findParent(findParent(parent[n]));
            }
            return parent[n];
        }

        bool merge(int n1,int n2,bool isJustCheck) {
            int p1 = findParent(n1);
            int p2 = findParent(n2);
            if(p1==p2) return true;
            if(isJustCheck) return false;
            if(rank[p1]>rank[p2]) {
                parent[p2]=p1;
                rank[p1]++;
            } else {
                parent[p1]=p2;
                rank[p2]++;
            }
            return false;
        }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionNode* root = new UnionNode(n);
        for(int i=1;i<nums.size();i++) {
            if(abs(nums[i]-nums[i-1])<=maxDiff) root->merge(i,i-1,0);
        }
        vector<bool> ans;
        for(auto query:queries) {
            ans.push_back(root->merge(query[0],query[1],1));
        }
        return ans;
    }
};