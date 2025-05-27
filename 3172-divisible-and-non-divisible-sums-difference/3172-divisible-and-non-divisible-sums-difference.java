class Solution {
    public int differenceOfSums(int n, int m) {
        int div = n/m;
        int sum = (n*(n+1))/2;
        int dsum = ((m * div * (div + 1)) / 2);
        int ndsum = sum - dsum;
        
        return ndsum - dsum;
    }
}