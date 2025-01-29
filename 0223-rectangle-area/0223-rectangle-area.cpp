class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        int area_a = (ax2 - ax1) * (ay2 - ay1);
        int area_b = (bx2 - bx1) * (by2 - by1);
        int olap_wid = max(0, min(ax2, bx2) - max(ax1, bx1));
        int olap_hei = max(0, min(ay2, by2) - max(ay1, by1));
        int olap_area = olap_wid * olap_hei;
        return area_a + area_b - olap_area;
    }
};