class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<int>> friendShipsToFix(m);
        vector<unordered_set<int>> communicationMap(n);

        for (int i = 0; i < m; i++) {
            for (auto lang : languages[i]) {
                communicationMap[lang - 1].insert(i);
            }
        }

        for (auto friendShip : friendships) {
            int f1 = friendShip[0] - 1;
            int f2 = friendShip[1] - 1;
            int flag = 0;
            for (auto l2 : languages[f2]) {
                if (communicationMap[l2 - 1].find(f1) != communicationMap[l2 - 1].end()) {
                    flag = 1; break;
                }
            }
            if (flag) continue;
            friendShipsToFix[f1].push_back(f2);
            friendShipsToFix[f2].push_back(f1);
        }

        unordered_set<int> brokenPeople;
        for (int i = 0; i < m; i++) {
            if (!friendShipsToFix[i].empty()) {
                brokenPeople.insert(i);
                for (auto f : friendShipsToFix[i]) {
                    brokenPeople.insert(f);
                }
            }
        }

        int res = INT_MAX;
        for (int lang = 0; lang < n; lang++) {
            int alreadyKnow = 0;
            for (auto person : brokenPeople) {
                if (communicationMap[lang].count(person)) alreadyKnow++;
            }
            int needTeach = brokenPeople.size() - alreadyKnow;
            res = min(res, needTeach);
        }

        return res == INT_MAX ? 0 : res;
    }
};



/*


1       ---------       4

|                       |
|                       |
|                       |

2       ---------       3





*/