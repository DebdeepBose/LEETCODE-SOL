class Solution {
public:
    int maxContainers(int n, int w, int maxW) {
        int maxAc = maxW / w;
        int cells = n * n;
        if (maxAc < cells) {
            return maxAc;
        } else if (maxAc > cells) {
            return cells;
        }

        return cells;
    }
};