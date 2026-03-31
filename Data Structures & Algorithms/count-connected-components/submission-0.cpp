class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for(int node = 0; node < n; node++) {
            if (!visit[node]) {
                dfs(node, adj, visit);
                res++;
            }
        }
        return res;
    }

private:
    void dfs(int edge, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[edge] = true;
        for (int nei : adj[edge]) {
            if (!visit[nei]) {
                dfs(nei, adj, visit);
            }
        }
    }
};
