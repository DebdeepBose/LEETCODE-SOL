class Solution {
public:
    string triangleType(vector<int>& v) {
        int a = v[0];
        int b = v[1];
        int c = v[2];
        if (a + b > c && a + c > b && b + c > a) {
            if (a == b && b == c) {
                return "equilateral";
            } else if (a != b && b != c && a != c) {
                return "scalene";
            } else {
                return "isosceles";
            }
        }

        return "none";
    }
};