class Solution {
public:
    int countMonobit(int n) {
        int x = 0;
        int c = 0;
        while (pow(2, x) - 1 <= n) {
            c++;
            x++;
        }
        return c;
    }
};