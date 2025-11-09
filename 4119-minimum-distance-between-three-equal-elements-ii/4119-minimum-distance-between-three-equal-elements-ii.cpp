class Solution {
public:
    int minimumDistance(vector<int>& v) {
        unordered_map<int, vector<int>> mp;

        int n = v.size();

        for (int i = 0; i < n; i++) {
            mp[v[i]].push_back(i);
        }

        int minDist = INT_MAX;

        for (auto e : mp) {

            int num = e.first;
            vector<int> vec = e.second;

            int i = 0;
            int j = 1;
            int k = 2;
            while (k < vec.size()) {
                int dist = abs(vec[i] - vec[j]) + abs(vec[j] - vec[k]) +
                           abs(vec[k] - vec[i]);

                minDist = min(minDist, dist);

                i++;
                j++;
                k++;
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};