class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        char max_digit = '0';
        int max_i = -1;
        int swap_i = -1, swap_j = -1;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] > max_digit) {
                max_digit = s[i];
                max_i = i;
            } else if (s[i] < max_digit) {
                swap_i = i;
                swap_j = max_i;
            }
        }

        if (swap_i != -1) {
            swap(s[swap_i], s[swap_j]);
        }

        return stoi(s);
    }
};
