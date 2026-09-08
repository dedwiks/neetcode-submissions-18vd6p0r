class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int leftmax = heights[l];
        int rightmax = heights[r];
        int res = 0;

        while (l < r) {
            if (leftmax < rightmax) {
                l++;
                leftmax = max(leftmax, heights[l]);
                res+= leftmax - heights[l];
            } else {
                r--;
                rightmax = max(rightmax, heights[r]);
                res+= rightmax - heights[r];
            }
        }
        return res;
    }
};
