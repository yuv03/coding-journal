class Solution {
public:

    bool detect(int node, vector<vector<int>>& graph, vector<int>& vis) {

        vis[node] = 0;

        queue<int> q;
        q.push(node);

        while (!q.empty()) {

            int val = q.front();
            q.pop();

            for (auto adjVal : graph[val]) {

                // Same color found
                if (vis[adjVal] == vis[val]) {
                    return false;
                }

                // Not visited
                else if (vis[adjVal] == -1) {

                    if (vis[val] == 0)
                        vis[adjVal] = 1;
                    else
                        vis[adjVal] = 0;

                    q.push(adjVal);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> vis(V, -1);

        for (int i = 0; i < V; i++) {

            if (vis[i] == -1) {

                if (!detect(i, graph, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};