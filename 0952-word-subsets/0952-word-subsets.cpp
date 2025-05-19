class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<int> cnt(26, 0), tmp(26);

        for (auto e : w2) {
            fill(tmp.begin(), tmp.end(), 0);
            for (char ch : e) {
                tmp[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                cnt[i] = max(cnt[i], tmp[i]);
            }
        }

        vector<string> ans;
        for (auto w : w1) {
            vector<int> freq(26, 0);
            for (char ch : w) {
                freq[ch - 'a']++;
            }
            bool isValid = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < cnt[i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans.push_back(w);
            }
        }

        return ans;
    }
};
