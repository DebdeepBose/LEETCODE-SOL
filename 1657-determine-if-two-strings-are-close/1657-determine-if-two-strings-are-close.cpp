class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int m = w1.size();
        int n = w2.size();
        if (m != n) {
            return false;
        }
        unordered_map<char, int> mp1, mp2;
        vector<int> u;
        vector<int> v;
        string a, b;
        int c = 1;
        int d = 1;
        for (int i = 0; i < m; i++) {
            mp1[w1[i]]++;
            mp2[w2[i]]++;
        }
        for (auto e : mp1) {
            u.push_back(e.second);
            a += (e.first);
        }
        for (auto e : mp2) {
            v.push_back(e.second);
            b += (e.first);
        }
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (u != v || a != b) {
            return false;
        }
        return true;
    }
};