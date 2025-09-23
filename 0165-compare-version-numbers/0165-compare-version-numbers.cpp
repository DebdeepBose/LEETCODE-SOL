class Solution {
public:
    int compareVersion(string version1, string version2) {

        vector<int> v1;
        vector<int> v2;

        string s = "";
        for (auto e : version1) {
            if (e == '.') {
                int x = stoi(s);
                v1.push_back(x);
                s = "";
                continue;
            }
            s += e;
        }
        if (!s.empty()) {
            int x = stoi(s);
            v1.push_back(x);
        }
        s = "";
        for (auto e : version2) {
            if (e == '.') {
                int x = stoi(s);
                v2.push_back(x);
                s = "";
                continue;
            }
            s += e;
        }
        if (!s.empty()) {
            int x = stoi(s);
            v2.push_back(x);
        }
        int i = 0;
        int j = 0;
        int m = v1.size();
        int n = v2.size();

        if (n < m) {
            int diff = m - n;
            while (diff--) {
                v2.push_back(0);
            }
            n = v2.size();
        } else if (m < n) {
            int diff = n - m;
            while (diff--) {
                v1.push_back(0);
            }
            m = v1.size();
        }

        while (i < m && j < n) {
            if (v1[i] > v2[j]) {
                return 1;
            } else if (v1[i] < v2[j]) {
                return -1;
            } else {
                i++;
                j++;
            }
        }

        return 0;
    }
};