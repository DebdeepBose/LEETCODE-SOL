class Solution {
public:
    int countHillValley(std::vector<int>& v) {
        int n = v.size();
        int c = 0;
        int left = 0;

        for (int i = 1; i < n - 1; i++) {
            if (v[i] != v[i + 1]) {
                if ((v[i] > v[left] && v[i] > v[i + 1]) ||
                    (v[i] < v[left] && v[i] < v[i + 1])) {
                    c++;
                }
                left = i;
            }
        }

        return c;
    }
};