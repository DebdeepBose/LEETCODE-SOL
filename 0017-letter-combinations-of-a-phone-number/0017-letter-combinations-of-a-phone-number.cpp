class Solution {
public:
    void findAllLetterCombinations(int index, string digits, int n,
                                   vector<string>& letterCombination,
                                   string temporaryCombinations,
                                   vector<string>& hashMap) {
        if (temporaryCombinations.size() == n) {
            letterCombination.push_back(temporaryCombinations);
            return;
        }

        int hashIndex = digits[index] - '0';
        for (auto hashChar : hashMap[hashIndex]) {

            // Take the current element
            temporaryCombinations.push_back(hashChar);
            findAllLetterCombinations(index + 1, digits, n, letterCombination,
                                      temporaryCombinations, hashMap);

            // Do not take the current element
            temporaryCombinations.pop_back();

            /* Now u might think dont we call that function once again, yeah we
             * do but not here cuz we are already looping, its effectively the
             * same thing*/
        }
    }

    vector<string> letterCombinations(string digits) {
        /* Another tricky ahh recursion problem, btw i came to know TODAY, yes
         * today after 1.5yrs that when we solve for a particular rec-tree block
         * we can omit it, i have been reusing it for my entire life, anyways
         * lets move on, Now unlike the previous ones where we had a set value
         * for arrays or atleast a defining index from n -> 0 or i -> n we dont
         * have that here so we gotta whip one up ourselves and the best way to
         * do it, is using a Hashmap, we keep "" i.e empty string for first 2
         * indices cuz like there are no letters linked to those so yeah*/

        vector<string> hashMap = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // Aight so we did that now lets finish initiating the rest of the stuff

        int n = digits.size();

        // If string is empty we return nothing
        if (n == 0) {
            return {};
        }

        vector<string> letterCombination;

        string temporaryCombinations = "";

        // Yeah after a long time we taking index
        int index = 0;

        findAllLetterCombinations(index, digits, n, letterCombination,
                                  temporaryCombinations, hashMap);

        return letterCombination;
    }
};