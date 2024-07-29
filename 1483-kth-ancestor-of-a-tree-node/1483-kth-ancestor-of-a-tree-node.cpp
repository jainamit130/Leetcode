class TreeAncestor {
public:
    vector<vector<int>> binaryLift;
    TreeAncestor(int n, vector<int>& parent) {
        binaryLift.resize(17,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            binaryLift[0][i]=parent[i];
        }
        for(int j=1;j<17;j++){
            for(int i=0;i<n;i++){
                if(binaryLift[j-1][i]!=-1)
                    binaryLift[j][i]=binaryLift[j-1][binaryLift[j-1][i]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<17;i++){
            int bit=(k>>i)&(1);
            if(bit==1){
                node=binaryLift[i][node];
                if(node==-1)
                    return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */