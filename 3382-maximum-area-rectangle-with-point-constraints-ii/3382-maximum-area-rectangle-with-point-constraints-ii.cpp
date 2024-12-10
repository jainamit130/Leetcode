class SegTree {
    public:
    int maxY;
    int leftI;
    int rightI;
    SegTree* left;
    SegTree* right;
    SegTree(int l,int r) {
        leftI = l;
        rightI = r;
        left=NULL;
        right = NULL;
        maxY = INT_MIN;
    }

int updateTree(SegTree* root, int index, int val) {
    if (root->leftI == root->rightI && index == root->leftI) {
        root->maxY = max(root->maxY, val);
        return root->maxY;
    }

    int m = (root->leftI + root->rightI) / 2;
    int leftMax = INT_MIN, rightMax = INT_MIN;

    if (index <= m) {
        if (root->left == NULL) {
            root->left = new SegTree(root->leftI, m);
        }
        leftMax = updateTree(root->left, index, val);
    }

    if (index > m) {
        if (root->right == NULL) {
            root->right = new SegTree(m + 1, root->rightI);
        }
        rightMax = updateTree(root->right, index, val);
    }

    root->maxY = max(leftMax, rightMax); 
    return root->maxY;
}


int getMaxY(SegTree* root, int l, int r) {
    if (root == NULL) {
        return INT_MIN;
    }

    if (root->leftI > r || root->rightI < l) {
        return INT_MIN;
    }

    if (root->leftI >= l && root->rightI <= r) {
        return root->maxY;
    }

    int mid = (root->leftI + root->rightI) / 2;

    int leftMax = INT_MIN;
    if (root->left != NULL && l <= mid) {
        leftMax = getMaxY(root->left, l, min(mid, r)); 
    }

    int rightMax = INT_MIN;
    if (root->right != NULL && r > mid) {
        rightMax = getMaxY(root->right, max(mid + 1, l), r); 
    }

    return max(leftMax, rightMax);
}

};

class Solution {
public:
    long long maxRectangleArea(vector<int>& x, vector<int>& y) {
        map<int,vector<int>> mp;
        SegTree* root = new SegTree(0,1e8+1);
        int n = x.size();
        for(int i=0;i<n;i++) {
            mp[y[i]].push_back(x[i]);
        }

        int ans = INT_MIN;
        for(auto [y,xs]:mp) {
            sort(xs.begin(),xs.end());
            for(int i=0;i<xs.size()-1;i++) {
                int y1 = root->getMaxY(root,xs[i],xs[i]);
                int y2 = root->getMaxY(root,xs[i+1],xs[i+1]);
                if(y1==y2 && y1!=y && y1!=INT_MIN) {
                    int ymid = root->getMaxY(root,xs[i]+1,xs[i+1]-1);
                    if(ymid<y1) {
                        ans = max(ans,(xs[i+1]-xs[i])*abs(y1-y));
                    }
                } 
            }

            for(auto x:xs) {
                root->updateTree(root,x,y);
            }
        }
        if(ans==INT_MIN){
            return -1;
        }
        return ans;

    }
};


/*

x1          x2

    y1... 

Steps
Create a Map y -> xs
Sort => based on x's
then => get max from left and max from right

1   1   2   3   3

1       2   1   3
3

------------------
3       2   1   3


*/