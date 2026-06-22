class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        for (int i = 0; i < graph.size(); i++) {
            vector<int> color(graph.size(), -1);
            queue<int> q;
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (auto adjacentNode : graph[node]) {
                    if (color[adjacentNode] == -1) {
                        q.push(adjacentNode);
                        if (color[node] == 0) {
                            color[adjacentNode] = 1;
                        } else {
                            color[adjacentNode] = 0;
                        }
                    } else if (color[adjacentNode] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};