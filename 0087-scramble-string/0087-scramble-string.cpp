class Solution {
public:
    unordered_map<string,bool> cache;
    bool isScramble(string s1, string s2) {
        return dfs(s1,s2);
    }

    bool dfs(string s,string target){
        if(s==target)
            return true;
    
        if(cache.find(s+"-"+target)!=cache.end()){
            return cache[s+"-"+target];
        }

        bool ans=false;
        for(int i=1;i<s.length();i++){
            //split
            ans=ans 
                ||  (dfs(s.substr(0,i),target.substr(0,i))
                &&  dfs(s.substr(i,s.length()-i),target.substr(i,s.length()-i)));
            //swap
            ans=ans 
                ||  (dfs(s.substr(i,s.length()-i),target.substr(0,s.length()-i))
                &&  dfs(s.substr(0,i),target.substr(s.length()-i,i)));
        }
        return cache[s+"-"+target]=ans;
    }
};

/*
substring(0,i+1); substring(i+1,n-i-1)

g   r   e   a   t


r   g   e   a   t


*/