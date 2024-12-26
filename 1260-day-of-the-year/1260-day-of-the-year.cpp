class Solution {
public:
    int finduntilmon(int x, vector<int>& v) {
        int d = 0;
        for (int i = 0; i < x; i++) {
            d += v[i];
        }
        return d;
    }
    int dayOfYear(string s) {
        string r = s.substr(0, 4);
        int n = stoi(r);
        int c = 0;
        bool leap = false;
        if (n % 4 == 0 && n % 400 == 0) {
            leap = true;
        } else if (n % 4 == 0 && n % 400 != 0) {
            if (n % 100 != 0) {
                leap = true;
            }
        }
        int day = stoi(s.substr(8, 2));
        int mon = stoi(s.substr(5, 2));
        vector<int> v = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int add = finduntilmon(mon, v);
        if (leap && mon > 2) {
            c += add + 1;
        } else {
            c += add;
        }
        c += day;
        return c;
    }
};