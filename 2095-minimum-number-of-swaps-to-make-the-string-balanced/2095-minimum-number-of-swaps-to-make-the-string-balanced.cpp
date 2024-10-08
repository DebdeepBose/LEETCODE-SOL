class Solution {
public:
    int minSwaps(string s) {
        int cap = 0;
        for (auto e : s) {
            if (e == '[') {
                cap++;
            } else {
                if (cap > 0) {
                    cap--;
                }
            }
        }
        return (cap + 1) / 2;
    }
};