class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis){
        vis[node] = 1;

        for(auto &it : adj[node]){
            int next = it.first;
            int dist = it.second;

            ans = min(ans, dist);

            if(!vis[next]){
                dfs(next, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis);

        return ans;
    }
};