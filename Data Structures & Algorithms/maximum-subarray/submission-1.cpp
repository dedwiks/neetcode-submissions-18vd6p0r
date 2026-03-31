class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int cur = 0;
            for (int j = i; j < nums.size(); j++) {
                cur += nums[j];
                res = max(res, cur);
            }
        }
        return res;
    }
};
