class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0, r = heights.size()-1;

        while(l<r){
            int maximum = (r - l) * min(heights[l], heights[r]);
            if(heights[l] < heights[r]){
                l++;
            } 
            else if(heights[r] < heights[l]){
                r--;
            }
            else if(heights[r] == heights[l]){
                l++;
            }
            res = max(maximum, res);

        }
        return res;
    }
};
