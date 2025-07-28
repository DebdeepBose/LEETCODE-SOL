class Solution {
public:
    bool check(vector<int>& v) {

        // Storing the array size
        int n = v.size();

        // If n is 0 / 1, it means the array is sorted regardless
        if (n == 0 || n == 1) {
            return true;
        }

        // Initialize the number of dips :- drops in value
        int dip = 0;

        // Run a loop to calculate such dips
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                dip++;
            }
        }

        // Edge case
        if (v.back() > v.front()) {
            dip++;
        }

        // If the number of dips are less than equal to 1, its sorted and
        // rotated.
        return dip <= 1;
    }
};