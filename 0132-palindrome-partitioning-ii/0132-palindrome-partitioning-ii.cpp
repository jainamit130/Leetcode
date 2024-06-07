class Solution {
public:
    int minCut(string s) {
        vector<int> cache(2001,INT_MAX);
        if(s.length()==1)
            return 0;
        return dfs(s,0,cache)-1;
    }

    int dfs(string s,int index,vector<int>& cache){
        if(index>=s.length()){
            return 0;
        }

        if(cache[index]!=INT_MAX){
            return cache[index];
        }

        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i))
                cache[index]=min(cache[index],1+dfs(s,i+1,cache));
        }
        return cache[index];
    }

    bool isPalindrome(string& s,int index,int k){
        int i=index,j=k;
        if(i==j)
            return true;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            } else 
                return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     int minCut(string s) {
//         if(isPalindrome(s,0,s.length()-1))
//             return 0;
//         vector<vector<int>> cache(s.length()+1,vector<int>(s.length(),-1));
//         for(int i=1;i<=s.length()-1;i++){
//             if(dfs(s,0,i,cache)){
//                 return i-1;
//             }
//         }
//         return s.length()-1;
//     }

//     int dfs(string s,int index,int noofpartitions,vector<vector<int>>& cache){
//         if(index>=s.length() && noofpartitions==0){
//             return 1;
//         }

//         if(noofpartitions<=0)
//             return 0;

//         if(cache[index][noofpartitions]!=-1)
//             return cache[index][noofpartitions];

//         cache[index][noofpartitions]=0;
//         for(int i=index;i<s.length();i++){
//             if(isPalindrome(s,index,i))
//                 cache[index][noofpartitions]=cache[index][noofpartitions]||dfs(s,i+1,noofpartitions-1,cache);
//         }
//         return cache[index][noofpartitions];
//     }

//     bool isPalindrome(string s,int index,int k){
//         int i=index,j=k;
//         if(i==j)
//             return true;
//         while(i<j){
//             if(s[i]==s[j]){
//                 i++;j--;
//             } else 
//                 return false;
//         }
//         return true;
//     }
// };