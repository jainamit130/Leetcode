class Solution {
public:
    int mono(const string& s){
        if(s.empty()) return 0;
        int cnt = 1;
        int ans = 1;
        for(int i = 1; i < (int)s.size(); i ++){
            if(s[i] == s[i - 1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        return ans;
    }

    int duo(const string& s, char c1, char c2){
        map<int, int> pos;
        pos[0] = -1;
        int ans = 0;
        int delta = 0;
        for(int i = 0; i < (int)s.size(); i ++){
            if(s[i] != c1 && s[i] != c2){
                pos.clear();
                pos[0] = i;
                delta = 0;
                continue;
            }
            if(s[i] == c1){
                delta++;
            }
            else{
                delta--;
            }
            if(pos.find(delta) != pos.end()){
                ans = max(ans, i - pos[delta]);
            }
            else{
                pos[delta] = i;
            }
        }
        return ans;
    }

    int trio(const string& s){
        vector<int> cnt(3, 0);

        map<vector<int>, int> pos;
        pos[{0, 0}] = -1;

        int ans = 0;

        for(int i = 0; i < (int)s.size(); i++){
            cnt[s[i] - 'a']++;

            vector<int> key = {cnt[1] - cnt[0], cnt[2] - cnt[0]};

            if(pos.find(key) != pos.end()){
                ans = max(ans, i - pos[key]);
            }
            else{
                pos[key] = i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        return max({
            mono(s),
            duo(s, 'a', 'b'),
            duo(s, 'a', 'c'),
            duo(s, 'b', 'c'),
            trio(s)
        });
    }
};
// class Solution {
// public:
//     int longestBalanced(string s) {
//         int ans = 1;
//         int n = s.length();
//         vector<vector<int>> prefix(1,{0,0,0});
//         vector<int> continuousCount(3,0);
//         for(char ch1='a';ch1<='c';ch1++) {
//             continuousCount[ch1-'a']=(s[0]==ch1);   
//         }
//         unordered_map<int,int> hash1;
//         map<vector<int>,int> hash2;
//         for(int i=0;i<n;i++) {
//             int a = (s[i]=='a'?1:0) + prefix.back()[0];
//             int b = (s[i]=='b'?1:0) + prefix.back()[1];
//             int c = (s[i]=='c'?1:0) + prefix.back()[2];
//             prefix.push_back({a,b,c});
//             if(i>0) {
//                 // check prev char if same then inc count else reset
//                 if(s[i]==s[i-1]) {
//                     continuousCount[s[i]-'a']=continuousCount[s[i]-'a']+1;
//                     ans = max(ans,continuousCount[s[i]-'a']);
//                     for(char ch1='a';ch1<='c';ch1++) {
//                         if(s[i]==ch1) continue;
//                         continuousCount[ch1-'a']=0;
//                     }
//                 }
//             }
//             // a-b; b-c; a-c
//             unordered_set<int> st;
//             vector<int> h;
//             for(char ch1='a';ch1<='c';ch1++) {
//                 for(char ch2=ch1+1;ch2<='c';ch2++) {
//                     int dif = ch2-ch1;
//                     int diff = prefix[i+1][ch2-'a']-prefix[i+1][ch1-'a'];
//                     if(hash1.find(diff)!=hash1.end()) {
//                         ans=max(ans,i-hash1[diff]+1);
//                     } else {
//                         hash1[diff]=i;
//                     }

//                     if(st.find(abs(dif))!=st.end()) {
//                         h.push_back(diff);
//                     }
//                     st.insert(abs(dif));
//                 }
//             }
//             if(hash2.find(h)!=hash2.end()) {
//                 ans = max(ans,hash2[h]-i+1);
//             } else  {
//                 hash2[h]=i;
//             }
//         }
//         return ans;
//     }
// };


/*



    a   b   a

0   1   0   1    
0   0   1   0
0   0   0   0
    -1  1   -1  (b-a)
    -1  0   -1  (c-a)
     0  -1   0  (c-b)


0   1   1   2
0   0   1   1
0   0   0   0


*/