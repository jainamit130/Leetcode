template<class T>
class SegmentTree
{
    #define left(i) (2*i + 1)
    #define right(i) (2*i + 2)
    #define parent(i) ((i-1)/2)
public:
        //tree constructors.
        SegmentTree(vector<T> data, T value, T (*combine)(T obj1, T obj2))
        {
            this->combine = combine;
            valueForExtraNodes = value;
            segTreeSize = calculateSize(data.size());
            buildTree(data);
        }
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2))
        {
            this->combine = combine;
            valueForExtraNodes = value;
            segTreeSize = calculateSize(n);

            vector<T> data;
            for(int i = 0; i < n; i++)
                data.push_back(ar[i]);

            buildTree(data);
        }
        
        //query the range l to r, 0 based array indexing.
        T query(int l, int r)
        {
            int st = 0, ed = segTreeSize/2;
            return queryHelper(l, r, st, ed, 0);
        }
        
        //update the element at index idx to val.
        void update(int idx, T val)
        {
            int segTreeIdx = (segTreeSize/2) + idx;
            tree[segTreeIdx] = val;
            while(parent(segTreeIdx) >= 0)
            {
                segTreeIdx = parent(segTreeIdx);
                if(right(segTreeIdx) < segTreeSize)
                tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
                if(segTreeIdx == 0)
                    break;
            }
        }
        ///TODO lazy propagation
private:
        //represents the segment tree.
        T *tree;
    
        //builds the segment tree.
        void buildTree(vector<T> data)
        {
            int n = data.size();
            tree = new T[segTreeSize];
            int extraNodes = (segTreeSize/2 + 1) - n;
            for(int i = segTreeSize - 1; i >= 0; i--)
            {
                if(extraNodes>0)
                    {
                        tree[i] = valueForExtraNodes;
                        extraNodes--;
                    }
                else if(n>0)
                    {
                        tree[i] = data[n-1];
                        n--;
                    }
                else
                    tree[i] = combine(tree[left(i)], tree[right(i)]);
            }
        }
        
        //size of the segment tree array.
        int segTreeSize;
    
        //extra nodes must be added to array to make its size a power of 2
        //this is the value to be filled for the those nodes.
        T valueForExtraNodes;
    
        //specifies how to combine child node results to form parent node result.
        T (*combine)(T obj1, T obj2);
    
        //used to calculate the size of array needed to store the tree.
        int calculateSize(int n)
        {
            int pow2 = 1;
            while( pow2 < n)
            {
                pow2 = pow2 << 1;
            }
            return 2*pow2 - 1;
        }
    
        //helps to solve a range query.
        T queryHelper(int l,int r, int st, int ed, int node)
        {
            if( (r < st) || (l > ed) || (l > r) )
                return valueForExtraNodes;
            if(st >= l && ed <= r)
                return tree[node];
            T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
            T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
            return combine(leftVal, rightVal);
        }
};

class Solution {
public:
    int closestToTarget(vector<int>& v, int k) {
        SegmentTree<int> tree(v,(1ll<<31)-1,[](int a,int b){return a&b;});
        int n = v.size();
        auto nearest_value = [&](int l){
            int st = l, ed = n-1;
            while(ed-st > 1){
                int m = (st+ed)>>1;
                int t = tree.query(l,m);
                if(t > k) st = m;
                else ed = m;
            }
            int a = tree.query(l,st);
            int b = tree.query(l,ed);
            if(a < k) a = k-a;
            else a = a-k;
            
            if(b < k) b = k-b;
            else b = b-k;
            return min(a,b);
        };

        
        int ans = 1e9;
        for(int l=0; l<n; ++l){
            int near = nearest_value(l);
            ans = min(ans,near);
        }
        return ans;
    }
};