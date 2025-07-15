class Solution {
public:
    int minOperations(int n) {
        if (n % 2 == 0) {
            return (n * n) / 4;
        }
        //i found this had to scrible like 4 pages
        return (n * n / 2) - ((n * n) / 4 + ((n * n) / 4 + 1)) / 2;
    }
    
}; 
