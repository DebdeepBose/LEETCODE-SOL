class Solution {
public:
    int minimizeMax(vector<int>& v, int p) {
        if (p == 0) {
            return 0;
        }

        sort(v.begin(), v.end());

        int minThrehold = 0;
        int maxThrehold = v.back() - v[0];

        while (minThrehold < maxThrehold) {
            int candidateThrehold = minThrehold + (maxThrehold - minThrehold) / 2;
            int pairs = 0;

            for (int i = 1; i < v.size(); i++) {
                if (candidateThrehold >= v[i] - v[i - 1]) {
                    pairs++;
                    i++;
                }
            }

            if (pairs >= p) {
                maxThrehold = candidateThrehold;
            } else {
                minThrehold = candidateThrehold + 1;
            }
        }

        return minThrehold;
    }
};
