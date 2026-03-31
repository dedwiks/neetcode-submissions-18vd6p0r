class Solution {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string res;
public:
    string foreignDictionary(vector<string>& words) {
        for (const string& word : words) {
            for (char ch : word) {
                adj[ch];
            }
        }
        for (size_t i = 0; i < words.size() - 1; i++) {
            const string& w1 = words[i], & w2 = words[i + 1];
            size_t minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        for (const auto& pair : adj) {
                if (dfs(pair.first)) {
                    return "";
                }
            }
            reverse(res.begin(), res.end());
            return res;
    }
    bool dfs(char ch) {
        if (visited.find(ch) != visited.end()) {
            return visited[ch];
        }
        visited[ch] = true;

        for (char next : adj[ch]) {
            if (dfs(next)) {
                return true;
            }
        }
        visited[ch] = false;
        res.push_back(ch);
        return false;
    }

};
