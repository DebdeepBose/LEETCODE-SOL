class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / __gcd(p, q);
        int x = lcm / q;
        int y = lcm / p;
        int rcp[2][2] = {{3, 2}, {0, 1}};
        return rcp[1 & x][1 & y];
    }
};