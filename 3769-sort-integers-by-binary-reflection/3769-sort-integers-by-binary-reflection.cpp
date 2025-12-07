class Solution {
public:
    vector<int> sortByReflection(vector<int>& v) {
        vector<string> tmp;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            string s = "";
            int num = v[i];
            while (num > 0) {
                s = s + to_string(num % 2);
                num = num / 2;
            }
            tmp.push_back(s);
        }

        vector<int> r;
        for (auto e : tmp) {
            r.push_back(stoi(e, 0, 2));
        }

        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({r[i], v[i]});
        }

        sort(vp.begin(), vp.end());

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(vp[i].second);
        }

        return ans;
    }
};
