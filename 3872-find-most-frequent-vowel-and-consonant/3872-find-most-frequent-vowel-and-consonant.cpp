class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int vow = 0;
        int con = 0;
        for (auto el : mp) {
            if (el.first == 'a' || el.first == 'e' || el.first == 'i' ||
                el.first == 'o' || el.first == 'u') {
                vow = max(vow, el.second);
            } else {
                con = max(con, el.second);
            }
        }
        return vow + con;
    }
};