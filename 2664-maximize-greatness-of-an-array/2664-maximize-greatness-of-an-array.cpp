class Solution {
public:
    int maximizeGreatness(vector<int>& v) {
        sort(v.begin(), v.end());
        int id = 0;
        for (auto e : v) {
            if (e > v[id]) {
                id++;
            }
        }
        return id;
    }
};