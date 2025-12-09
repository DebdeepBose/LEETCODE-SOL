class Solution {
public:
    int specialTriplets(vector<int>& v) {

        int maxi = ranges::max(v) * 2;
        vector<long long> prevFreq(maxi + 1);
        vector<long long> nextFreq(maxi + 1);

        const int mod = 1e9 + 7;

        for (auto e : v) {
            nextFreq[e]++;
        }

        long long ans = 0;

        for (auto e : v) {
            nextFreq[e]--;
            int t = 2 * e;
            ans = (ans + prevFreq[t] * nextFreq[t]) % mod;
            prevFreq[e]++;
        }

        return ans;
    }
};