class Solution {
public:
    int maximumSwap(int g) {
        string s = to_string(g);
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int maxindex = i;
            for (int j = n - 1; j > i; j--) {
                if (s[j] > s[maxindex]) {
                    maxindex = j;
                }
            }
            if (s[maxindex] > s[i]) {
                swap(s[maxindex], s[i]);
                break;
            }
        }

        return stoi(s);
    }
};
