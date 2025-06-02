class Solution {
public:
    vector<bool> isPrime;
    vector<int> segTree;
    vector<int> lazy;
    map<int,set<int>> primeOccurences;
    int n,maxEle=1e5+1;

    void updateTree(int start,int end,int low,int high,int change,int pos) {
        if(start>end) return;

        if(lazy[pos]!=0) {
            segTree[pos]+=lazy[pos];
            if(start!=end) {
                lazy[2*pos+1]+=lazy[pos];
                lazy[2*pos+2]+=lazy[pos];
            }
            lazy[pos]=0;
        }

        // non overlap
        if(high<start || end<low) return;

        // total overlap
        if(low<=start && end<=high) {
            segTree[pos] += change;
            if(start!=end) {
                lazy[2*pos+1]+=change;
                lazy[2*pos+2]+=change;
            }
            return;
        }

        // Partial overlap
        int mid = (start+end)/2;
        updateTree(start,mid,low,high,change,2*pos+1);
        updateTree(mid+1,end,low,high,change,2*pos+2);
        segTree[pos]=max(segTree[2*pos+1],segTree[2*pos+2]);
        return;
    }   

    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        isPrime.resize(maxEle+1,true);
        populatePrimes();

        vector<int> prefix(n+1);
        vector<int> suffix(n+1);

        for(int i=0;i<n;i++) {
            if(isPrime[nums[i]]) {
                if(primeOccurences.find(nums[i])==primeOccurences.end()) prefix[i+1]++;
                else suffix[*primeOccurences[nums[i]].rbegin()]--;
                suffix[i]++;
                primeOccurences[nums[i]].insert(i);
            }
        }

        for(int i=1,j=n;i<=n;i++,j--) {
            prefix[i]+=prefix[i-1];
            suffix[j-1]+=suffix[j];
        }

        vector<int> score(n-1);
        segTree.resize(4*(n-1),0);
        lazy.resize(4*(n-1),0);

        for(int i=1;i<n;i++) {
            score[i-1]=prefix[i]+suffix[i];
            updateTree(0,n-2,i-1,i-1,score[i-1],0);
        }
        vector<int> ans;
        for(auto query:queries) {
            int index = query[0];
            int val = query[1];
            int origVal = nums[index];
            if(val==origVal) {
                ans.push_back(segTree[0]+lazy[0]);
                continue;
            }
            processNum(origVal,index,false);
            processNum(val,index,true);
            ans.push_back(segTree[0]+lazy[0]);
            nums[index] = val;
        }

        return ans;
    }

    void processNum(int val,int index,bool toAdd) {
        if(!isPrime[val]) return;
        if(primeOccurences.find(val)!=primeOccurences.end()) updatePrimeOccurence(val,-1);
        if(toAdd) primeOccurences[val].insert(index);
        else {
            primeOccurences[val].erase(index); 
            if(primeOccurences[val].size()==0) primeOccurences.erase(val);
        }
        if(primeOccurences.find(val)!=primeOccurences.end()) updatePrimeOccurence(val,1);
    }

    void updatePrimeOccurence(int val,int change) {
        int low = *primeOccurences[val].begin();
        int high = *primeOccurences[val].rbegin();
        updateTree(0,n-2,low,n-2,change,0);
        updateTree(0,n-2,0,high-1,change,0);
    }

    void populatePrimes() {
        isPrime[0]=false; isPrime[1]=false;
        for(int i=2;i*i<=maxEle;i++) {
            if(isPrime[i]) {
                for(int j=i*i;j<=maxEle;j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        return;
    }
};



/*

Conclusions:
1. store the primes in seive 
2. iterate and store the prime occurences in a map<int,set>
3. create primeOpenCount and primeCloseCount => create prefix and suffix => get prefix + suffix
4. segment tree stores the prefix + suffix and do updates in lazy tree
5. Possible operations in segment tree =>
    i.   Non Prime -> prime => +1
    ii.  Prime -> prime => -1 then +1
    iii. Non Prime -> Non Prime => no change required
    iv.  Prime -> Non Prime => -1
6. if a operation affects the first occrence or last occurence then a update is needed in the suffix range i+1 -> j and prefix range i -> j-1
7. for each operation change => update the occurences map


Dry Run

0   1   2   3   4   5   6   7   8   9   10  11   
2   6   5   9   7   7   2   3   4   2   8   11



Prime map
2   3   5   7   11


Map of prime -> set:
2 -> 0,6,9
3 -> 7,7
5 -> 2,2
7 -> 4,5
11 -> 11,11


prime start count
0   1   2   3   4   5   6   7   8   9   10  11
1   0   1   0   1   0   0   1   0   0   0   1
1   1   2   2   3   3   3   4   4   4   4   5

prime close count
0   1   2   3   4   5   6   7   8   9   10  11
0   0   1   0   0   1   0   1   0   1   0   1
5   5   5   4   4   4   3   3   2   2   1   1


prefix + suffix
6   6   7   6   7   7   6   7   6   6   6   6

query => 9 -> 1


0   1   2   3   4   5   6   7   8   9   10  11   
2   6   5   9   7   7   2   3   4   1   8   11

Map of prime -> set:
2 -> 0,6
3 -> 7,7
5 -> 2,2
7 -> 4,5
11 -> 11,11

Suffix change
7 - 9 => -1

prime start count
0   1   2   3   4   5   6   7   8   9   10  11
1   0   1   0   1   0   0   1   0   0   0   1
1   1   2   2   3   3   3   4   4   4   4   5

prime close count
0   1   2   3   4   5   6   7   8   9   10  11
0   0   1   0   0   1   0   1   0   1   0   1
5   5   5   4   4   4   3   2   1   1   1   1

prefix + suffix
0   1   2   3   4   5   6   7   8   9   10  11
6   6   7   6   7   7   6   6   5   5   6   6


*/