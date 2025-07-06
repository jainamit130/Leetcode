class Solution {
public:
    using ll = long long;
    ll maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());
        vector<int> starts,ends;
        vector<ll> prefix(1);
        int n = coins.size();
        for(auto coin:coins) {
            starts.push_back(coin[0]);
            ends.push_back(coin[1]);
            prefix.push_back(prefix.back() + 1ll*(coin[1]-coin[0]+1)*coin[2]);
        }

        ll ans = 0;
        for(int i=0;i<coins.size();i++) {
            int start1 = coins[i][0];
            int end2 = coins[i][1];
            
            int end1 = start1+k-1;
            int start2 = max(0,end2-k+1);

  
            ll subAns = 0;       
            int endIndex = min(search(starts,end1,i,n-1),n-1);
            cout<<"End: "<<endIndex<<" ";
            subAns += prefix[endIndex+1] - prefix[i];
                subAns -= (coins[endIndex][1]-max(end1,coins[endIndex][0]-1)) * coins[endIndex][2];
            cout<<subAns<<endl;
            ans = max(ans,subAns);
   
            subAns = 0;       
            int startIndex = max(0,search(ends,start2,0,i));
            cout<<"Start: "<<startIndex<<" "; 
            subAns += prefix[i+1] - prefix[startIndex];
            subAns -= (max(coins[startIndex][0]+1,start2)-coins[startIndex][0]) * coins[startIndex][2];
            cout<<subAns<<endl;
            ans = max(ans,subAns);
        }
        return ans;
    }

    int search(vector<int>& coins,int val,int start,int end) {
        int index = lower_bound(coins.begin()+start,coins.begin()+end,val)-coins.begin();
        return index;
    }
};


/*

k = 22

            0

31  0
1   0
10  18  6   54

64  26
1   1
43  47  3   69



*/