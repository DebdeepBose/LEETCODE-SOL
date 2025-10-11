class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int n = image.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                image[i][j] = !image[i][j];
            }
            int l = 0;
            int r = n - 1;
            while (l <= r) {
                swap(image[i][l], image[i][r]);
                l++;
                r--;
            }
        }

        return image;
    }
};