class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Map(26);
        int size=s1.length();
        for(int i=0;i<size;i++){
            s1Map[s1[i]-'a']++;
        }

        int i=0,j=0;
        vector<int> s2Map(26);
        while(j<s2.length()){
            if(j-i<size){
                s2Map[s2[j]-'a']++;
                j++;
            } else {
                if(j-i==size){
                    if(s1Map==s2Map){
                        return true;
                    }
                }

                s2Map[s2[j]-'a']++;
                j++;


                s2Map[s2[i]-'a']--;
                i++;
            }
        }
        if(j-i==size){
            if(s1Map==s2Map){
                return true;
            }
        }
        return false;
    }
};