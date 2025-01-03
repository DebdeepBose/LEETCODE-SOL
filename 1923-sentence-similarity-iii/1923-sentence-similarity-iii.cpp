class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        auto split = [](const string& s) {
            vector<string> v;
            string r = "";
            for (auto e : s) {
                if (e == ' ') {
                    if (!r.empty()) {
                        v.push_back(r);
                        r = "";
                    }
                } else {
                    r += e;
                }
            }
            if (!r.empty()) {
                v.push_back(r);
            }
            return v;
        };
        vector<string> r1 = split(s1);
        vector<string> r2 = split(s2);
        if (r1.size() < r2.size()) {
            swap(r1, r2);
        }
        int n = r1.size();
        int m = r2.size();
        int i = 0;
        int j = 0;

        while (i < n && i < m && r1[i] == r2[i]) {
            i++;
        }
        while (j < n && j < m && r1[n - j - 1] == r2[m - j - 1]) {
            j++;
        }
        return i + j >= m;
    }
};