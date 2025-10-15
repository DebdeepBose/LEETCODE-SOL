class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        
        vector<vector<int>> revAdj(V);
        vector<int> inDegree(V, 0);
        
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                revAdj[v].push_back(u);
                inDegree[u]++;
            }
        }

    
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for (auto prev : revAdj[node]) {
                inDegree[prev]--;
                if (inDegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};
