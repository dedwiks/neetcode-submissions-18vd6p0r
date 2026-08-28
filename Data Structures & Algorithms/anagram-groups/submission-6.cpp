class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (const auto& str : strs) {
            string sortedS = str;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(str);
        }

        vector<vector<string>> result;

        for (const auto& r : res) {
            result.push_back(r.second);
        }
        return result;
    }
};
