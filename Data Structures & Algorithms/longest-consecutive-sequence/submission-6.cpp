class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int res = 0;

        for (const auto& num : numset) {
            int longest = 0;
            if (numset.find(num - 1) == numset.end()) {
                longest = 1;
                while (numset.find(num + longest) != numset.end()) {
                    longest++;
                }
            }
            res = max(res, longest);
        }
        return res;
    }
};
