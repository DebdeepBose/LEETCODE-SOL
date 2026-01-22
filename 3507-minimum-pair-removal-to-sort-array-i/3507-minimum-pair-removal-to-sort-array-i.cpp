class Solution {
private:
    int minPair(vector<int>& v, int n) {
        int minSum = INT_MAX;
        int idx = -1;

        for (int i = 0; i < n - 1; i++) {
            if (v[i] + v[i + 1] < minSum) {
                minSum = v[i] + v[i + 1];
                idx = i;
            }
        }
        return idx;
    }

    void mergePair(vector<int>& v, int idx) {
        v[idx] = v[idx] + v[idx + 1];
        v.erase(v.begin() + idx + 1);
    }

    bool checkSorted(vector<int>& v) { 
        return is_sorted(v.begin(), v.end()); 
    }

public:
    int minimumPairRemoval(vector<int>& v) {
        int ops = 0;

        while (!checkSorted(v)) {
            int idx = minPair(v, v.size());
            mergePair(v, idx);
            ops++;
        }

        return ops;
    }
};
