class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       map<int,int> mp;
       for(auto n:arr1){
        mp[n]++;
       } 
       int i=0;
       for(auto n:arr2){
            while(mp.size() && mp[n]>0){
                arr1[i]=n;
                i++;
                mp[n]--;
                if(mp[n]==0){
                    mp.erase(n);
                }
            }   
       }
       for(auto [a,b]:mp){
            for(int j=0;j<b;j++){
                arr1[i]=a;
                i++;
            }
       }
        return arr1;
    }
};