class Solution {
public:
    int minOperations(int n) {
        if (n % 2 == 0) {
            return (n * n) / 4;
        }
        //i found this lol (had to scrible like 4 pages
        return (n * n / 2) - ((n * n) / 4 + ((n * n) / 4 + 1)) / 2;
    }
}; // 0 1 2 4 6 9 12 16 20 25 30
   // 1 2 3 4 5 6  7  8  9 10 11
