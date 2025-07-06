class AuthenticationManager {
public:
    unordered_map<string,int> mp;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]=currentTime+ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId)!=mp.end()){
            if(mp[tokenId]<=currentTime){
                mp.erase(tokenId);
            } else {
                mp[tokenId]=ttl+currentTime;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans=0;
        for(auto [a,b]:mp){
            if(b>currentTime){
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */