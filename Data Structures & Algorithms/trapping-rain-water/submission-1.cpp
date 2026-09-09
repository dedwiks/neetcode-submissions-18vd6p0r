class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;

        int maxleft = height[0];
        int maxright = height[height.size() - 1];

        while (l < r) {
            if (maxleft < maxright) {
                l++;
                maxleft = max(maxleft, height[l]);
                int vol = maxleft - height[l];
                res += vol;
            } else {
                r--;
                maxright = max(maxright, height[r]);
                int vol = maxright - height[r];
                res += vol;
            }
        }
        return res;
    }
};
