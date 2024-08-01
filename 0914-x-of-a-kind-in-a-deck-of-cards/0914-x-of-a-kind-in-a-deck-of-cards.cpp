class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> mp(10001);
        int mini=INT_MAX;
        for(auto d:deck){
            mp[d]++;
        }

        for(auto n:mp){
            if(n==0)
                continue;
            if(n==1){
                return false;
            }

            mini=min(n,mini);
        }

        int gcd=mini;
        for(int i=2;i*i<=mini;i++){
            if(mini%i==0){
                gcd=i;
                break;
            }
        }

        for(auto n:mp){
            if(n%gcd!=0){
                return false;
            }
        }
        return true;
    }
};