class Solution {
public:
    int gcd(vector<int>& v) {
        int vgcd = v[0];
        for (int i = 1; i < v.size(); i++) {
            vgcd = ::gcd(vgcd, v[i]);
        }
        return vgcd;
    }

    long long lcm(vector<int>& v) {
        long long val = v[0];
        for (int i = 1; i < v.size(); i++) {
            val = (val * v[i]) / ::gcd((long long)val, (long long)v[i]);
        }
        return val;
    }

    long long maxScore(vector<int>& v) {
        int Tgcd = gcd(v);
        long long Tlcm = lcm(v);
        long long maxFact = 1LL * Tgcd * Tlcm;
        for (int i = 0; i < v.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < v.size(); j++) {
                if (i != j) {
                    temp.push_back(v[j]);
                }
            }
            if (!temp.empty()) {
                int tempGcd = gcd(temp);
                long long tmpval = lcm(temp);
                maxFact = max(maxFact, (long long)tempGcd * tmpval);
            }
        }
        return maxFact;
    }
};
