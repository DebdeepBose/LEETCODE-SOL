class Solution {
public:
    int totalNumbers(vector<int>& v) {
        unordered_set<int> mp;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && i != k && j != k) {
                        if (v[i] != 0) {
                            if (v[k] % 2 == 0) { 
                                int num = v[i] * 100 + v[j] * 10 + v[k];
                                mp.insert(num);
                            }
                        }
                    }
                }
            }
        }
        return mp.size();
    }
};