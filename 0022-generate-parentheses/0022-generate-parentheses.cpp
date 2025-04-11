class Solution {
public:
    // Recursive helper to generate all valid combinations of parentheses
    void generateParenthesesHelper(int openCount, int closeCount, vector<string>& generatedParentheses, string currentStr, int totalPairs) {
        // Base case: if we have used all n open and n close brackets, add to result
        if (openCount == totalPairs && closeCount == totalPairs) {
            generatedParentheses.push_back(currentStr);
            return;
        }

        // Add an open bracket if we haven't used all of them yet
        if (openCount < totalPairs) {
            generateParenthesesHelper(openCount + 1, closeCount, generatedParentheses, currentStr + '(', totalPairs);
        }

        // Add a close bracket if it won't exceed the number of open brackets used
        if (closeCount < openCount) {
            generateParenthesesHelper(openCount, closeCount + 1, generatedParentheses, currentStr + ')', totalPairs);
        }
    }

    // Main function to initiate the generation process
    vector<string> generateParenthesis(int totalPairs) {
        vector<string> generatedParentheses;
        string currentStr = "";
        generateParenthesesHelper(0, 0, generatedParentheses, currentStr, totalPairs);
        return generatedParentheses;
    }
};
