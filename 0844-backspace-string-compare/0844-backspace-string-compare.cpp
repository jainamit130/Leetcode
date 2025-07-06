class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.length()-1;
        int j=t.length()-1;
        int count1=0;
        int count2=0;
        while(i>=0 && j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    count1++;
                    i--;
                } else if(count1>0){
                    count1--;
                    i--;
                } else {
                    break;
                }
            }

            while(j>=0){
                if(t[j]=='#'){
                    count2++;
                    j--;
                } else if(count2>0){
                    count2--;
                    j--;
                } else {
                    break;
                }
            }

            if((i>=0 && s[i]=='#') || (j>=0 && t[j]=='#'))
                continue;

            if(i>=0 && j>=0){
                if(s[i]!=t[j])
                    return false;
                else {
                    i--;j--;
                }
            }
            
        }

                   while(i>=0){
                if(s[i]=='#'){
                    count1++;
                    i--;
                } else if(count1>0){
                    count1--;
                    i--;
                } else {
                    break;
                }
            }


                    while(j>=0){
                if(t[j]=='#'){
                    count2++;
                    j--;
                } else if(count2>0){
                    count2--;
                    j--;
                } else {
                    break;
                }
            }
        if(i>=0 || j>=0)
            return false;
        return true;
    }
};

// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         string s1="";
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='#'){
//                 if(s1.length()>0){
//                     s1.pop_back();
//                 }
//             } else {
//                 s1+=s[i];
//             }
//         }
//         string s2="";
//         for(int i=0;i<t.length();i++){
//             if(t[i]=='#'){
//                 if(s2.length()>0){
//                     s2.pop_back();
//                 }
//             } else {
//                 s2+=t[i];
//             }
//         }
//         return s1==s2;
//     }
// };