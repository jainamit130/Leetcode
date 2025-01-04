class Solution {
public:
    bool hasMatch(string s, string p) {
        int splitIndex = p.find('*');
        string p1 = p.substr(0,splitIndex);
        string p2 = p.substr(splitIndex+1);

        if(p1.length()==0 && p2.length()==0) return true;
        int p1MatchIndex = 0;
        if(p1.length()) {
            p1MatchIndex = s.find(p1);
            if(p1MatchIndex<0) return false;
        }

        int p2MatchIndex = 0;
        if(p2.length()) {
            p2MatchIndex = s.find(p2,p1MatchIndex+p1.size());
            if(p2MatchIndex<0) return false;
        }
        return true;
    }
};

/*

p="*"
p1 size and p2 size = 0
p1 size =0 
p2 size = 0

*/