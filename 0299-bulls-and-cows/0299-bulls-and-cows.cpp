class Solution {
public:
    string getHint(string s, string g) {
        int n = s.size();
        int bulls = 0, cows = 0;
        unordered_map<char, int> mps, mpg;

        for (int i = 0; i < n; i++) {
            if (s[i] == g[i]) {
                bulls++;
            } else {
                mps[s[i]]++;
                mpg[g[i]]++;
            }
        }

        for (auto e : mps) {
            char ch = e.first;
            cows += min(e.second, mpg[ch]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
