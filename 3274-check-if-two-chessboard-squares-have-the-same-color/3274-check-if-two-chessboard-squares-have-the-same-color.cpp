class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a = coordinate1[0]-'a'+1+coordinate1[1]-48;
        int b = coordinate2[0]-'a'+1+coordinate2[1]-48;
        return a%2==b%2;
    }
};