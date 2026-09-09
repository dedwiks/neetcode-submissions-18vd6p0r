class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> charset;

        for (const auto& s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            charset[sortedS].push_back(s);
        }

        vector<vector<string>> res;

        for (const auto& ch : charset) {
            res.push_back(ch.second);
        }
        return res;
    }
};
