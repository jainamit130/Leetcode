class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> allPossiblePrefix;
        int ans=0;
        findAllPrefixes(arr1,allPossiblePrefix);
        for(int i=0;i<arr2.size();i++){
            int number=arr2[i];
            while(number){
                if(allPossiblePrefix.find(number)!=allPossiblePrefix.end()){
                    string s=to_string(number);
                    int len=s.length();
                    ans=max(ans,len);
                }
                number/=10;
            }
        }
        return ans;
    }

    void findAllPrefixes(vector<int>& arr,set<int>& allPossiblePrefix){
        for(int i=0;i<arr.size();i++){
            int number=arr[i];
            while(number){
                allPossiblePrefix.insert(number);
                number/=10;
            }
        }
    }
};