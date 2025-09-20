class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        /* Alright so as we know upper_bound provides the first character
         * greater than 'c' here, so we do that*/
        int charIndex = upper_bound(letters.begin(), letters.end(), target) -
                        letters.begin();

        /* In case upper bound fails to find the character, it returns the
         * length of the array so we put up a check*/
        if (charIndex < n) {
            return letters[charIndex];
        }
        return letters[0];
    }
};