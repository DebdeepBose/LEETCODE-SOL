class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // Initialize prefix and suffix products
        int prefixProd = 1;
        int suffixProd = 1;

        // Track the maximum product seen so far
        int maxProductSoFar = INT_MIN;

        for (int i = 0; i < n; i++) {

            // Reset prefix product if a zero is encountered (multiplying by 0 ruins continuity)
            if (prefixProd == 0) {
                prefixProd = 1;
            }

            // Reset suffix product similarly
            if (suffixProd == 0) {
                suffixProd = 1;
            }

            // Multiply prefix product by the current left-side element
            prefixProd *= nums[i];

            // Multiply suffix product by the current right-side element
            suffixProd *= nums[n - i - 1];

            // Update the global max product using the max of both ends
            maxProductSoFar = max(maxProductSoFar, max(prefixProd, suffixProd));
        }

        return maxProductSoFar;
    }
};
