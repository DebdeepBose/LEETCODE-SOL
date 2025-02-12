class Solution {
public:
    int finddsum(int e) {
        int s = 0;
        while (e > 0) {
            int tmp = e % 10;
            s += tmp;
            e /= 10;
        }
        return s;
    }

    int maximumSum(vector<int>& v) {
        unordered_map<int, int> sumMap;
        int maxs = -1;

        for (auto e : v) {
            int d = finddsum(e);
            if (sumMap.find(d) != sumMap.end()) {
                int tmps = sumMap[d] + e;
                maxs = max(maxs, tmps);
            }
            sumMap[d] = max(sumMap[d], e);
        }

        return maxs;
    }
};
