class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Wow i actually brute forced this
        vector<int> v1;
        vector<int> v2;

        string s = "";
        for (auto e : version1) {
            if (e == '.') {
                int x = stoi(s); // O(k), k = length of this chunk
                v1.push_back(x);
                s = "";
                continue;
            }
            s += e;
        } // So this loop is O(L1), where L1 = version1.size()

        if (!s.empty()) {
            int x = stoi(s); // O(k), but total across all chunks is O(L1)
            v1.push_back(x);
        }

        s = "";
        for (auto e : version2) {
            if (e == '.') {
                int x = stoi(s); // O(k), again per chunk
                v2.push_back(x);
                s = "";
                continue;
            }
            s += e;
        } // Another O(L2), where L2 = version2.size()

        if (!s.empty()) {
            int x = stoi(s); // O(k), but total across chunks = O(L2)
            v2.push_back(x);
        }

        int i = 0;
        int j = 0;
        int m = v1.size();
        int n = v2.size();

        if (n < m) {
            int diff = m - n;
            while (diff--) {
                v2.push_back(0); // O(diff), at most O(|m-n|)
            }
            n = v2.size();
        } else if (m < n) {
            int diff = n - m;
            while (diff--) {
                v1.push_back(0); // O(diff), at most O(|m-n|)
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
        } // They traverse together → O(max(m, n))

        return 0;

        // So overall O(L1+L2) dominates
    }
};
