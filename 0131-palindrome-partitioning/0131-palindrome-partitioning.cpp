class Solution {
public:
    bool isPalindrome(string stringToCheck) {
        int left = 0;
        int right = stringToCheck.size() - 1;

        while (left < right) {
            if (stringToCheck[left] != stringToCheck[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void findAllPalindromePartitions(string s, int n,
                                     vector<vector<string>>& validPalindromes,
                                     vector<string>& temporaryParts,
                                     int indexTracker) {
        // Base Case
        if (indexTracker == n) {
            validPalindromes.push_back(temporaryParts);
            return;
        }

        /*Since its a string we need to traverse1 all its parts and then chcek
           whether that substring is a palindrome or not yeah we be calling
           another function to check plaindrome*/

        for (int i = indexTracker; i < n; i++) {

            /*Understadn this .substr(startingPosition, lengthFromStartPos)
            this is the syntax basically if we have a string "abc" and I put
            .substr(0,2) this means it will consider the substring from position
            0 upto a length of two, 0 included so "ab" would be stored, NOT
            "abc", 2 isnt the index ITS DA LENGTH*/
            string tempString = s.substr(indexTracker, i - indexTracker + 1);

            // Now we check if it our substring is a plaindrome or not
            if (isPalindrome(tempString)) {

                // If it is a palindrome we recursively call the next part,
                // basically we trying to place our cuts
                temporaryParts.push_back(tempString);
                findAllPalindromePartitions(s, n, validPalindromes,
                                            temporaryParts, i + 1);
                // Undo choice
                temporaryParts.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        /* Aight so, this is one of those question that screams DP, i mean
         * anything can be dp if you try hard enough XDDD, anyways we'll go
         * step-wise to solve this, lets create them DS and variables*/

        int n = s.size();

        vector<vector<string>> validPalindromes;
        vector<string> temporaryParts;

        /* We will take tempString later, also this time i'm keeping an
        indexTracker, why u many ask? and the answer is IDK, it helps*/

        int indexTracker = 0;

        findAllPalindromePartitions(s, n, validPalindromes, temporaryParts,
                                    indexTracker);

        return validPalindromes;
    }
};