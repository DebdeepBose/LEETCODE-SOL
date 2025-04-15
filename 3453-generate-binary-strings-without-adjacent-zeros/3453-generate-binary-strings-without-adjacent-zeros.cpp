class Solution {
public:
    // Helper Function
    void generateAllBinaryStrings(vector<string>& binaryStrings, string& temporaryBinaryString, int n, int zeroCount, int oneCount) {
                                  
        // If the sum of the number of zeroes and ones equal to n we , backtrack
        if (zeroCount + oneCount == n) {

            // Push the temporary string into the list of strings
            binaryStrings.push_back(temporaryBinaryString);
            return;
        }

        //Append 1 since it has no restrictions
        temporaryBinaryString += '1';

        //Recursively call the generate function and increment oneCount by 1
        generateAllBinaryStrings(binaryStrings, temporaryBinaryString, n, zeroCount, oneCount + 1);

        //Pop the previously added 1                         
        temporaryBinaryString.pop_back();

        if (temporaryBinaryString.empty() || temporaryBinaryString.back() != '0') {

            //Append a zero if the condition is fullfilled
            temporaryBinaryString += '0';

            //Recursively call the generate function and increment zeroCount by 0
            generateAllBinaryStrings(binaryStrings, temporaryBinaryString, n, zeroCount + 1, oneCount);

            //Make sure to pop it                         
            temporaryBinaryString.pop_back();
        }
    }

    // Main Function
    vector<string> validStrings(int n) {

        // All binaryStrings to return
        vector<string> binaryStrings;

        // Temporary string to store and push it into returning vector
        string temporaryBinaryString = "";

        // These will store the counts
        int totalCountOfZeros = 0;
        int totalCountOfOnes = 0;

        // Recursive function to add all the combinations
        generateAllBinaryStrings(binaryStrings, temporaryBinaryString, n, totalCountOfZeros, totalCountOfOnes);

        return binaryStrings;
    }
};

