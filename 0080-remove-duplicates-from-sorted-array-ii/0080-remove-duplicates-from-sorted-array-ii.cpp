class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        map<int, int> mp;
        for (auto e : v) {
            mp[e]++;
        }
        v.clear();
        for (auto e : mp) {
            if (e.second <= 2) {
                while (e.second--) {
                    v.push_back(e.first);
                }
            } else {
                v.push_back(e.first);
                v.push_back(e.first);
            }
        }
        return v.size();
    }
};