class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (auto e : s) {
            freq[e - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int del = 0;
        for (int i = freq.size() - 2; i >= 0; i--) {
            if (freq[i] == 0) {
                break;
            }
            if (freq[i] >= freq[i + 1]) {
                int prevFreq = freq[i];
                freq[i] = max(0, freq[i + 1] - 1);
                del += prevFreq - freq[i];
            }
        }
        return del;
    }
};