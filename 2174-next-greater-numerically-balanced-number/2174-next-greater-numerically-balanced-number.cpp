class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i < 10000000; i++) {
            string t = to_string(i);
            vector<int> mp(10, 0);
            for (int j = 0; j < t.size(); j++) {
                mp[t[j] - '0']++;
            }
            bool f = true;
            for (int j = 0; j < mp.size(); j++) {
                if (mp[j] > 0 && mp[j] != j) {
                    f = false;
                    break;
                }
            }
            if (f) {
                return i;
            }
        }
        return -1;
    }
};