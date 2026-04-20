class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            int maximum = (r - l) * min(heights[l], heights[r]);
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[r] < heights[l]) {
                r--;
            } else {
                l++;
            }
            res = max(res, maximum);
        }
        return res;
    }
};
