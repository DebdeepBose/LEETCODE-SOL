class Solution {
public:
    int maximumSwap(int g) {
        string s = to_string(g);
        int n = s.length();

        for (int j = 0; j < n; j++) {
            int maxindex = j;
            for (int i = n - 1; i > j; i--) {
                if (s[i] > s[maxindex]) {
                    maxindex = i;
                }
            }
            if (s[maxindex] > s[j]) {
                swap(s[maxindex], s[j]);
                break;
            }
        }

        return stoi(s);
    }
};
