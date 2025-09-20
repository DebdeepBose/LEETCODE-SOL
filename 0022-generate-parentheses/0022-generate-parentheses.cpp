class Solution {
public:
    void generateParanthesesPair(int leftParanthesesCount,
                                 int rightParanthesesCount, int n,
                                 string tempString,
                                 vector<string>& stringList) {

        /*I mean yeah if the total count == n we push our string into the vector
         * and return nothing cuz its void */
        if (leftParanthesesCount + rightParanthesesCount == n * 2) {
            stringList.push_back(tempString);
            return;
        }

        /*Yeah cuz there might be a consition where u go n/2 +1 number of left
         * parantheses which is not what we want*/
        if (leftParanthesesCount < n) {
            // Take '(' and recurse
            tempString += '(';
            generateParanthesesPair(leftParanthesesCount + 1,
                                    rightParanthesesCount, n, tempString,
                                    stringList);
            tempString.pop_back(); // Backtrack
        }

        /* We can only take ')' if there are more '(' than ')' so far */
        if (rightParanthesesCount < leftParanthesesCount) {
            tempString += ')';
            generateParanthesesPair(leftParanthesesCount,
                                    rightParanthesesCount + 1, n, tempString,
                                    stringList);
            tempString.pop_back(); // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        /* Yeah so simple way to solve this is we take either '(' or ')'
        but first lets adjust some variables and call the function
        */

        if (n == 0) {
            return {};
        }

        // YEah we gotta maintain their count, i'll explain later
        int leftParanthesesCount = 0;
        int rightParanthesesCount = 0;

        string tempString = "";

        // Here we store our tempStrings
        vector<string> stringList;

        generateParanthesesPair(leftParanthesesCount, rightParanthesesCount, n,
                                tempString, stringList);

        return stringList;
    }
};
