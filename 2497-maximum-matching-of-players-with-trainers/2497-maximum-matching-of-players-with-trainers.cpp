class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& v, vector<int>& s) {
        sort(v.begin(), v.end());
        sort(s.begin(), s.end()); 

        if (v[0] > s.back()) {
            return 0;
        }

        int c = 0;
        int i = 0;
        int j = 0;

        while (i < v.size() && j < s.size()) {
            if (v[i] <= s[j]) {
                c++;
                i++;
                j++;
            } else if (v[i] > s[j]) {
                j++;
            }
        }

        return c;
    }
};