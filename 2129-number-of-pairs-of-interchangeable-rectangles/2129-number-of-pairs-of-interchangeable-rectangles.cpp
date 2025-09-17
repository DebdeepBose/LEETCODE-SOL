class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& v) {
        int n = v.size();

        /* Aight so basically we go thru all elements in v and kinda do this, by
         * this i mean like divide the larger number by smoler one and increase
         * its count in the map by 1 or ++ whatever, in double of course*/

        unordered_map<double, int> mp;
        for (int i = 0; i < n; i++) {
            mp[(double)v[i][1] / (double)v[i][0]]++;
        }
        long long in = 0;

        /* I found the pattern that
        1->0
        2->1
        3->2
        4->6
        5->10
        6->15

        yeah so if we have n , summation of 1->n-1 gives us the value we need
        */

        for (auto e : mp) {
            if (e.second > 1) {
                long long el = e.second - 1;
                long long sum = el * (el + 1) / 2;

                // Here we add that value to the sum
                in += sum;
            }
        }
        return in;
    }
};