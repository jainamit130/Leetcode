class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        char ch = word[0];
        int n =word.length();
        int endIndex = n-numFriends;
        int length = endIndex+1;
        int index = 0;
        for(int i = 1;i<word.length();i++) {
            if(word[i]>=ch) {
                int newEndIndex = i+n-numFriends;
                if(newEndIndex<i && newEndIndex>=n) continue;
                int newLen = newEndIndex - i + 1;
                if(word[i]>ch || (word[i]==ch && length<newLen)) {
                    ch = word[i];
                    length = newLen;
                    index = i;
                }
            }
        }

        return word.substr(index,length);
    }
};


/*

10
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x


index + (n-length) >= numFriends 

length = index + n - numFriends


*/