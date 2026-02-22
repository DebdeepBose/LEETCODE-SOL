class Solution {
public:
    int compress(vector<char>& v) {
        int n = v.size();
        int c = 0;
        char cur = v[0];
        string s = "";
        for (int i = 0; i < n; i++) {
            if (v[i] == cur) {
                c++;
            } else if (v[i] != cur) {
                s += cur;
                if (c > 1) {
                    s += to_string(c);
                }
                cur = v[i];
                c = 1;
            }
        }
        s += cur;
        if (c > 1) {
            s += to_string(c);
        }
        v.clear();
        for (auto& ch : s) {
            v.push_back(ch);
        }
        return v.size();
    }
};