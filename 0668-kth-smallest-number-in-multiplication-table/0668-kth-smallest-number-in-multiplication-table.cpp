class Solution {
public:
    int countNumsLessThanMid(int mid, int m, int n) {
        /* Now there is a sleek way to do this, if u have notice carefully, the
        multiplication table is just the simple number-table like 1 2 3 -> 1*1,
        1*2, 1*3 2 4 6 -> 2*1, 2*2, 2*3

        so what we do if we check our rowNumber and divide our mid by it aka
        mid/rownNumber we get how many elements there are, but there is a catch
        , suppose our mid is 6 but total number of columns (i.e m) is 4 then
        there arent enough elements even tho 6/1 (i==1) = 6 so we take
        min(mid/i,n) and add it to our count*/
        int countOfNumsSmallerThanMid = 0;

        for (int i = 1; i <= m; i++) {
            countOfNumsSmallerThanMid += min(mid / i, n);
        }

        return countOfNumsSmallerThanMid;
    }
    int findKthNumber(int m, int n, int k) {
        /*Aight this question is also a Div 2-D CF problem so its a little
         tricky but do-able*/

        // First as usual we try to get the seacrh space
        int low = 1;
        int high = m * n; // Very understandable

        /* So we pick mid and count how many numbers in the table are less than
            or equal to mid. If the count is greater than or equal to k,
            we need a smaller number, so we move high to mid minus one.
            If the count is smaller than k, we  need a bigger number,
            so we move low to mid plus one.*/

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalCountOfNumsSmallerThanMid =
                countNumsLessThanMid(mid, m, n);

            if (totalCountOfNumsSmallerThanMid >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};