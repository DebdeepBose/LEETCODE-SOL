class Solution {
public:
    int minimumLength(string s) {
        vector<int> v(26, 0);
        int maxlen = 0;
        for (char ch : s) {
            v[ch - 'a']++;
        }
        for (int e : v) {
            if (e == 0){ 
                continue;
            }            
            if (e % 2 == 0) {
                maxlen += 2;
            } else {
                maxlen += 1;
            }
        }
        return maxlen;
    }
};
