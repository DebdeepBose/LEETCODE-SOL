class Solution {
public:
    int uniqueXorTriplets(vector<int>& v) {
        int numOfOneRightShifts = 0;
        int size = v.size();
        if (size <= 2) {
            return size;
        }

        while (size > 0) {
            size >>= 1;
            numOfOneRightShifts++;
        }
        return pow(2, numOfOneRightShifts);
    }
};