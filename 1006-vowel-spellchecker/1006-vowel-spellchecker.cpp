class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        auto maskVowels = [](string s) {
            for (char& c : s) {
                char lc = tolower(c);
                c = (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' ||
                     lc == 'u')
                        ? '*'
                        : lc;
            }
            return s;
        };

        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap, vowelMap;

        for (auto& w : wordlist) {
            string lw = w;
            transform(lw.begin(), lw.end(), lw.begin(), ::tolower);
            if (!caseMap.count(lw))
                caseMap[lw] = w;

            string mw = maskVowels(w);
            if (!vowelMap.count(mw))
                vowelMap[mw] = w;
        }

        vector<string> ans;
        for (auto& q : queries) {
            if (exact.count(q))
                ans.push_back(q);
            else {
                string lq = q;
                transform(lq.begin(), lq.end(), lq.begin(), ::tolower);
                if (caseMap.count(lq))
                    ans.push_back(caseMap[lq]);
                else {
                    string mq = maskVowels(q);
                    ans.push_back(vowelMap.count(mq) ? vowelMap[mq] : "");
                }
            }
        }
        return ans;
    }
};
