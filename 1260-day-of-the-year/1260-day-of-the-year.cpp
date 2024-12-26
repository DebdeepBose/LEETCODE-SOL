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
        unordered_set<int> yr = {1904, 1908, 1912, 1916, 1920, 1924, 1928, 1932,
                                 1936, 1940, 1944, 1948, 1952, 1956, 1960, 1964,
                                 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996,
                                 2000, 2004, 2008, 2012, 2016, 2020, 2024};
        if (yr.find(n) != yr.end()) {
            leap = true;
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