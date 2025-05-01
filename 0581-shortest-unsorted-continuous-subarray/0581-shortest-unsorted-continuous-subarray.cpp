class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        vector<int> tmp(v.begin(), v.end());
        sort(tmp.begin(), tmp.end());
        int start = -1;
        int end = -1;
        bool flag = false;
        vector<bool> mp(v.size(), false);
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != tmp[i]) {
                flag = true;
                mp[i] = true;
            }
        }
        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] == true) {
                start = i;
                break;
            }
        }
        for (int i = mp.size() - 1; i >= 0; i--) {
            if (mp[i] == true) {
                end = i;
                break;
            }
        }
        if (!flag) {
            return end - start;
        }
        return end - start + 1;
    }
};