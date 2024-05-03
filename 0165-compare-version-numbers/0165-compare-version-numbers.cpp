class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;
        v1+=".";
        v2+=".";
        while (i < v1.length() || j < v2.length()) {
            int flag = 0;
            string s1 = "", s2 = "";
            while (i < v1.length() && v1[i] != '.') {
                if (v1[i] != '0' || flag) {
                    s1 += v1[i];
                    flag = 1;
                }
                i++;
            }flag=0;
            while (j < v2.length() && v2[j] != '.') {
                if (v2[j] != '0' || flag) {
                    s2 += v2[j];
                    flag = 1;
                }
                j++;
            }
            if(s1=="")
                s1="0";
            if(s2=="")
                s2="0";
            if(stoi(s1)<stoi(s2))
                return -1;
            else if(stoi(s1)>stoi(s2))
                return 1;
            i++;
            j++;
        }
        return 0;
    }
};