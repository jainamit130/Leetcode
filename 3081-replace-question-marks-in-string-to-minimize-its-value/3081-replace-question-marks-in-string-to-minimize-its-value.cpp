class Solution {
public:
    string minimizeStringValue(string str) {
        vector<int> charFreq(26, 0); 
        string temp;
        int questionCount = 0; 


        for (char ch : str) {
            if (ch == '?') {
                questionCount++;
            } else {
                charFreq[ch-'a']++;
            }
        }


        while (questionCount > 0) {
            char chosen = '#'; 
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (chosen == '#' || charFreq[chosen-'a'] > charFreq[ch-'a']) {
                    chosen = ch;
                }
            }
            temp.push_back(chosen); 
            charFreq[chosen-'a']++;
            questionCount--;
        }


        sort(temp.begin(), temp.end());
        

        int j = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '?') {
                str[i] = temp.at(j); 
                j++;
            }
        }

        return str;
    }
};