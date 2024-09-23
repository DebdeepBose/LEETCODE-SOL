class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size();
        vector<int> hash(n + 1, 0);
        for (auto e : v) {
            hash[e]++;
        }
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] > 1) {
                return i;
            }
        }
        return -1;
    }
};
