class Solution {
public:
    /* This is our big recursive function that tries to match word starting at
    position (rowIndex, colIndex) yeah and basically we gotta reach the end of
    the word, somehow uf we end up out of bounds we gotta handle that
    */
    bool searchWordFromHere(vector<vector<char>>& gameBoard, int rowIndex,
                            int colIndex, int charIndex, string& secretWord) {

        // If we reached the end of the word, we nailed it
        if (charIndex == secretWord.size())
            return true;

        // If we went out of bounds or current cell is not matching, bail out
        if (rowIndex < 0 || colIndex < 0 || rowIndex == gameBoard.size() ||
            colIndex == gameBoard[0].size() ||
            gameBoard[rowIndex][colIndex] != secretWord[charIndex])
            return false;

        // Store current character and mark as visited temporarily
        char savedChar = gameBoard[rowIndex][colIndex];
        gameBoard[rowIndex][colIndex] = '@';

        // Try all four directions: up, down, left, right
        bool found = searchWordFromHere(gameBoard, rowIndex - 1, colIndex,
                                        charIndex + 1, secretWord) ||
                     searchWordFromHere(gameBoard, rowIndex + 1, colIndex,
                                        charIndex + 1, secretWord) ||
                     searchWordFromHere(gameBoard, rowIndex, colIndex - 1,
                                        charIndex + 1, secretWord) ||
                     searchWordFromHere(gameBoard, rowIndex, colIndex + 1,
                                        charIndex + 1, secretWord);

        // Backtrack: restore the cell like nothing happened
        gameBoard[rowIndex][colIndex] = savedChar;

        return found;
    }

    /* Main function, loops through the board to find the start of our
     secretWord*/
    bool exist(vector<vector<char>>& gameBoard, string secretWord) {

        /* Loop through each cell and well we try to spot the first character
        and then we recurse*/
        for (int row = 0; row < gameBoard.size(); row++) {
            for (int col = 0; col < gameBoard[0].size(); col++) {

                // If we spot the first character and the recursive search
                // works, return true immediately
                if (gameBoard[row][col] == secretWord[0] &&
                    searchWordFromHere(gameBoard, row, col, 0, secretWord))
                    return true;
            }
        }

        // If we went through the whole board and found nothing, well GG i guess
        return false;
    }
};
