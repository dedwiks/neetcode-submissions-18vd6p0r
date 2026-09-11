class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int res = 0;

        for (const auto& num : numset) {
            if (numset.find(num - 1) == numset.end()) {
                int count = 1;
                while (numset.find(num + count) != numset.end()) {
                    count++;
                }

                res = max(res, count);
            }
        }
        return res; 
    }
};
