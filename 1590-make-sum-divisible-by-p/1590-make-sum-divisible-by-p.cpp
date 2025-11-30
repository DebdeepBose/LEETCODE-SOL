class Solution {
public:
    int minSubarray(vector<int>& v, int p) {
        long long vsum = accumulate(v.begin(), v.end(), 0LL);
        int rem = vsum % p;
        if (rem == 0) {
            return 0;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefixSum = 0;
        int minLength = v.size();

        for (int i = 0; i < v.size(); i++) {
            prefixSum += v[i];
            int currentMod = prefixSum % p;
            int targetMod = (currentMod - rem + p) % p;

            if (mp.find(targetMod) != mp.end()) {
                minLength = min(minLength, i - mp[targetMod]);
            }

            mp[currentMod] = i;
        }

        return minLength == v.size() ? -1 : minLength;
    }
};
