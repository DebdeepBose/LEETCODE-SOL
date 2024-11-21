class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string> v;
        string tmp;
        while (ss >> tmp) {
            v.push_back(tmp);
        }
        int maxlen = 0;
        for (auto e : v) {
            maxlen = max(maxlen, (int)e.length());
        }
        vector<string> ans(maxlen, "");
        for (int i = 0; i < maxlen; i++) {
            for (auto e : v) {
                if (i < e.length()) {
                    ans[i] += e[i];
                } else {
                    ans[i] += " ";
                }
            }
            while (ans[i].back() == ' ') {
                ans[i].pop_back();
            }
        }
        
        return ans;
    }
};
