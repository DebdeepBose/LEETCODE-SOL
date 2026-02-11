class Solution {
public:
    string triangleType(vector<int>& v) {
        if (v[0] == v[1] && v[1] == v[2]) {
            return "equilateral";
        } else if (v[0] + v[1] <= v[2] || v[0] + v[2] <= v[1] ||
                   v[1] + v[2] <= v[0]) {
            return "none";
        } else if (v[0] != v[1] && v[0] != v[2] && v[1] != v[2]) {
            return "scalene";
        } else {
            return "isosceles";
        }
    }
};