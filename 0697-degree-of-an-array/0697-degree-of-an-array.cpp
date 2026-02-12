class Solution {
public:
    int findShortestSubArray(vector<int>& v) {
        int maxFreq = 0;
        unordered_map<int, int> mp;
        for (auto& e : v) {
            mp[e]++;
        }
        for (auto& k : mp) {
            maxFreq = max(maxFreq, k.second);
        }
        int minLen = INT_MAX;

        int i = 0, j = 0;
        int n = v.size();

        mp.clear();

        while (j < n) {
            mp[v[j]]++;
            while (mp[v[j]] == maxFreq) {
                minLen = min(minLen, j - i + 1);
                mp[v[i]]--;
                i++;
            }
            while (mp[v[j]] > maxFreq) {
                mp[v[i]]--;
                i++;
            }
            j++;
        }

        return minLen;
    }
};