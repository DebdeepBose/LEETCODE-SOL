class Solution {
public:
    bool closeStrings(string w1, string w2) {
        vector<int> mp1(26);
        vector<int> mp2(26);

        for (auto e : w1) {
            mp1[e - 'a']++;
        }
        for (auto e : w2) {
            mp2[e - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (mp1[i] == 0 && mp2[i] != 0 || (mp1[i] != 0 && mp2[i] == 0)) {
                return false;
            }
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());

        for (int i = 0; i < 26; i++) {
            if (mp1[i] != mp2[i]) {
                return false;
            }
        }
        return true;
    }
};