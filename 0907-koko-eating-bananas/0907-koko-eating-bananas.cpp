class Solution {
public:
    double calculateHoursTaken(vector<int>& piles, int n, int eatingSpeed) {

        // Yeah we takin double
        double totalHoursTaken = 0;

        for (int i = 0; i < n; i++) {

            // ceil cause we cant take decimal, have to take the higher value
            totalHoursTaken += ceil((double)piles[i] / (double)eatingSpeed);
        }

        return totalHoursTaken;
    }

    int minEatingSpeed(vector<int>& piles, int hours) {

        int n = piles.size();

        // No elements so nothing to eat, poor koko's gonna to be hungry tonight
        if (n == 0) {
            return 0;
        }

        /*You can use low = 0 but thats kinda useless, becuase easting speed
        of 0??? that doesnt even make sense so just take 1*/
        int low = 1;

        /*Yeah I tried with high = INT_MAX , max_element is just faster, INT_MAX
        makes the search space unnecessarily huge */
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            // I'm naming it mid, but its the eating speed in reality
            int mid = low + (high - low) / 2;

            double hoursTaken = calculateHoursTaken(piles, n, mid);

            /*Image hours is 8 and we got like 5, so in order to increase the
             hours we gotta reduce the eatingSpeed and the other way as well,
             say we got 11, in order to get 8 we gotta increase the
             eatingSpeed */
            if (hoursTaken <= hours) {
                high = mid - 1;

                /*Also u might ask why <= and not <, because question asks us to
                 find minimum value of k, so say maybe 5 is valid ans but who
                 knows maybe 4 is valid too int that case we go for the lowest
                 value possible*/
            } else {
                low = mid + 1;
            }
        }
        // Yeah somehow low points to the ans
        return low;
    }
};