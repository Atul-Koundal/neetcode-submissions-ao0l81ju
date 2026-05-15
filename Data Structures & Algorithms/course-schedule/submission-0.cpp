class Solution {
public:
     bool dfs(unordered_map<int, vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& inRecursion,
             int u) {

        visited[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]) {

            if(!visited[v]) {

                if(dfs(adj, visited, inRecursion, v)) {
                    return true;
                }
            }

            else if(inRecursion[v]) {
                return true;
            }
        }

        inRecursion[u] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        for(auto &edge : prerequisites) {

            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {

                if(dfs(adj, visited, inRecursion, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};