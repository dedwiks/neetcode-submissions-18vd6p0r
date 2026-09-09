class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (const auto& num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> medium;

        for (const auto& c : count) {
            medium.push_back({c.second, c.first});
        }
        sort(medium.rbegin(), medium.rend());

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(medium[i].second);
        }
        return res;
    }
};
