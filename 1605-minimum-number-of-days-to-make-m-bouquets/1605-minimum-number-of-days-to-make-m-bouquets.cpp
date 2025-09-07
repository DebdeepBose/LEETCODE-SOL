class Solution {
public:
    bool check(vector<int>& bloomDay, int n, int mid, int k, int m) {
        int flower = 0, bouquet = 0;
        for (int i = 0; i < n; i++) {

            // We increase flower count if our mid aka our bloomDay >= bloomDay
            // of array
            if (mid >= bloomDay[i]) {
                flower++;

                // Yeah so if flower count racher k, it means we can make a
                // bouquet
                if (flower == k) {
                    bouquet++;
                    flower = 0;
                }

                // Have to reset flower count to 0, if it aint adjacent
            } else {
                flower = 0;
            }
        }

        /*Yeah >= not == cuz we might be able to make more bouquets than
         necessary which isnt a bad thing, more money for me ig*/
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        /* Actually i was tryin to check if m * k > n, but well integer overflow
         * strikes again and i had to resort to stone age techniques */
        if (m > n / k) {
            return -1;
        }

        /*We can take low as the minimum element and high as maximum because
         that makes sense i guess like say min element is 4 and u take low as
         3, its pretty much useless 3 isnt going to be a valid answer anyways
         */
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(bloomDay[i], low);
            high = max(bloomDay[i], high);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool enoughBouquetAcquired = check(bloomDay, n, mid, k, m);

            // Same as koko eating nana's, except here we use bool
            if (enoughBouquetAcquired) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // We could have taken another variable but low does the job as well
        return low;
    }
};