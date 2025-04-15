class Solution {
    
    // Recursive helper function to convert string to integer
    long convertStringToInt(string str, int sign, int index, long accumulatedResult) {

        // Clamp the result if it exceeds 32-bit signed integer range
        if (sign * accumulatedResult >= INT_MAX) {
            return INT_MAX;
        }
        if (sign * accumulatedResult <= INT_MIN) {
            return INT_MIN;
        }

        // Base case: if index out of bounds or current character is not a digit, return final result
        if (index >= str.size() || str[index] < '0' || str[index] > '9') {
            return sign * accumulatedResult;
        }

        // Recursive call: move to the next digit and update the result
        accumulatedResult = convertStringToInt(
            str, 
            sign, 
            index + 1, 
            (accumulatedResult * 10 + (str[index] - '0'))
        );

        return accumulatedResult;
    }

public:
    int myAtoi(string inputStr) {
        int index = 0;
        int length = inputStr.size();
        int sign = 1;

        //Skip leading whitespaces
        while (index < length && inputStr[index] == ' ') {
            index++;
        }

        //Handle sign
        if (index < length && inputStr[index] == '-') {
            sign = -1;
            index++;
        } else if (index < length && inputStr[index] == '+') {
            index++;
        }

        //Convert remaining characters to integer using recursion
        return convertStringToInt(inputStr, sign, index, 0);
    }
};
