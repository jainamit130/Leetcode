/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int match(string w1,string w2){
        int count=0;
        for(int i=0;i<6;i++){
            if(w1[i]==w2[i])
                count++;
        }
        return count;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        vector<string> candidates;
        for(auto s:words){
            candidates.push_back(s);
        }

        while(!candidates.empty()){
            string word=candidates[rand()%candidates.size()];
            int g=master.guess(word);
            if(g==6){
                return;
            }
            vector<string> temp;
            for(int i=0;i<candidates.size();i++){
                if(match(candidates[i],word)==g){
                    temp.push_back(candidates[i]);
                }
            }
            candidates=temp;
        }
    }
};