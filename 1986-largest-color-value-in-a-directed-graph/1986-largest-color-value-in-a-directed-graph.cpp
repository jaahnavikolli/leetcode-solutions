class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
         int n = colors.size();
        int m = edges.size();

        // Edge case: If there are no edges, each node is isolated.
        // Thus, the maximum color value along any path is 1 (each node itself).
        if (m == 0) return 1;

        // dp[i][j] stores the maximum number of times color 'a' + j appears
        // along any path starting from node i.
        vector<vector<int>> dp(n, vector<int>(26, 0));

        // Adjacency list of the reversed graph (to track dependencies in topological order).
        vector<vector<int>> adj(n);

        // Reverse the direction of edges: u -> v becomes v -> u
        for (int i = 0; i < m; i++) {
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // indegree[i] stores the number of incoming edges to node i in the reversed graph.
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto& it : adj[i]) {
                indegree[it]++;
            }
        }

        // Initialize the queue with nodes having indegree 0 (sources in the reversed graph).
        queue<int> qu;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }

        // cnt tracks the number of nodes processed; used for cycle detection.
        int cnt = 0;

        // maxi stores the maximum color value across all paths.
        int maxi = 1;

        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            cnt++;

            // Include the current node's color in its dp state.
            dp[node][colors[node] - 'a'] += 1;

            // Propagate dp values to parent nodes in the reversed graph.
            for (auto& it : adj[node]) {
                for (int i = 0; i < 26; i++) {
                    // Carry forward the maximum frequency of each color.
                    dp[it][i] = max(dp[it][i], dp[node][i]);
                }

                // Decrease indegree of parent node (as current node is processed).
                indegree[it]--;

                // If indegree becomes zero, it is ready to be processed.
                if (indegree[it] == 0) {
                    qu.push(it);
                }
            }
        }

        // After processing, extract the maximum frequency among all nodes and colors.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (indegree[i] == 0) {
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        // If not all nodes were processed, the graph contains a cycle.
        if (cnt != n) return -1;

        return maxi;
    }
};