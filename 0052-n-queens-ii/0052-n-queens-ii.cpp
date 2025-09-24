class Solution {
public:
    int totalNQueens(int n) {
        // Literally Same as nqueens in this one we simply gotta return the
        // number of Valid solutions ,ONCE AGAIN yeah ROW Is top -> bottom ,
        // COLUMN is left -> right, This is like the 70th time ive
        // to remind myself

        // COPY-PASTA FROM NQUEENS, go look at nqueens or u wont understand shi

        if (n == 1) {
            return 1;
        }
        if (n < 4) {
            return 0;
        }

        vector<string> temporaryBoard(n, string(n, '.'));
        int validSolutionCount = 0;
        int startingRow = 0;

        nqueens(n, validSolutionCount, temporaryBoard, startingRow);

        return validSolutionCount;
    }

    void nqueens(int n, int& validSolutionCount, vector<string>& temporaryBoard,
                 int row) {

        // Base case is simple
        if (row == n) {
            validSolutionCount++;
            return;
        }
        /*This mean we successfully came down from top to bottom by placing a
        queen per row, other wise our code wouldnt allow us to reach n*/

        for (int column = 0; column < n; column++) {

            // Gotta check this later
            if (isSafePosition(temporaryBoard, column, row, n)) {

                // NOWWW, if its safe we can place our queen on this position
                temporaryBoard[row][column] = 'Q';

                // Then we move to next row
                nqueens(n, validSolutionCount, temporaryBoard, row + 1);

                /*Now imagine on row 3 we cant place a queen, that means we
                screwed up on row 2, suppose we cant place a queen on row 3 cuz
                we placed a queen on (1,2) -> row-1, column-2, so as a
                responsible citizen of this planet and a sane human being we
                wanna move to row-1,column-3 right? btw we talking about 4*4 so
                rows & columns would be from 0->3. Anyways so if we move to
                column-3 we gotta fix our mess on column-2 so we simply put a
                '.' then move ahead*/

                temporaryBoard[row][column] = '.';
            }
        }
    }

    bool isSafePosition(vector<string>& temporaryBoard, int column, int row,
                        int n) {
        /*To check if its a safe position we gotta check if any queen is place
        on that row/column/top-left diagnoal/top right diagonal, yeah cuz if we
        are on row-2 we can only access row-3 if we successfully placed a queen
        on row-2 so no use of checking lower diagoals
        */

        // Vertical Check, vertical means top->bottom so we be traversing row
        // Remember traversing row means we keep column constant
        for (int i = 0; i < n; i++) {
            if (temporaryBoard[i][column] == 'Q') {
                return false;
            }
        }

        // Horizontal check, aka we traberse kolumn, row remains constant
        for (int i = 0; i < n; i++) {
            if (temporaryBoard[row][i] == 'Q') {
                return false;
            }
        }

        /*Top-left diagonal, if u use a pen 'n' a paper, try to plot out a
        matrix, u would see that if we wanna traverse diagonally top-left we can
        see this pattern : (3,3)-->(2,2)-->(1,1)-->(0,0) so thats basiaclly
        row--,col--
        */
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
            if (temporaryBoard[i][j] == 'Q') {
                return false;
            }
        }

        /*Top-right diagonal, u would see that if we wanna traverse diagonally
        top-right we can see this pattern : (3,0)-->(2,1)-->(1,2)-->(0,3) so
        thats basiaclly row--,col++
        */
        // We take j as column+1,cuz thats where we are starting from genius
        for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) {
            if (temporaryBoard[i][j] == 'Q') {
                return false;
            }
        }

        // IF none of the above checks fail we return true

        return true;
    }
};