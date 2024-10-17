class Solution {
public:
    int maximumSwap(int g) {
        string s = to_string(g);
        char maxch = '0';
        int maxi = -1, swapi = -1, swapj = -1;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > maxch) {
                maxch = s[i];
                maxi = i;
            } else if (s[i] < maxch) {
                swapi = i;
                swapj = maxi;
            }
        }
        if (swapi != -1) {
            swap(s[swapi], s[swapj]);
        }
        return stoi(s);
    }
};