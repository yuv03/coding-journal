class Solution {

private:

    bool dfs(int src, int color,
             vector<vector<int>>& graph,
             vector<int>& vis) {

        vis[src] = color;

        for (auto adjVal : graph[src]) {

            // Same color adjacent node
            if (vis[adjVal] == vis[src]) {
                return false;
            }

            // Not visited
            else if (vis[adjVal] == -1) {

                // Assign opposite color
                if (!dfs(adjVal, 1 - color, graph, vis)) {
                    return false;
                }
            }
        }

        return true;
    }

public:

    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> vis(V, -1);

        for (int i = 0; i < V; i++) {

            if (vis[i] == -1) {

                if (!dfs(i, 0, graph, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};