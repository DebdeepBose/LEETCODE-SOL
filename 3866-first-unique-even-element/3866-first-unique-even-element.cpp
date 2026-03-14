class Solution {
public:
    int firstUniqueEven(vector<int>& v) {
        int n = v.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                mp[v[i]]++;
            }
        }
        for (auto& e : v) {
            if (mp[e] == 1) {
                return e;
            }
        }
        return -1;
    }
};