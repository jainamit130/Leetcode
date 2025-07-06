class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(auto a:arr){
            mp[a]++;
        }
        int i=0;
        while(i<arr.size()){
            if(mp[arr[i]]==1){
                k--;
            }
            if(k==0){
                break;
            }
            i++;
        }
        if(k>0){
            return "";
        }
        return arr[i];
    }
};