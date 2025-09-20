class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char c) {
        int n = v.size();
        /* Alright so as we know upper_bound provides the first character
         * greater than 'c' here, so we do that*/
        int i = upper_bound(v.begin(), v.end(), c) - v.begin();

        /* In case upper bound fails to find the character, it returns the
         * length of the array so we put up a check*/
        if (i < n) {
            return v[i];
        }
        return v[0];
    }
};