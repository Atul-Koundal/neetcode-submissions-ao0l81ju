class Solution {
public:

    bool dfs(vector<vector<int>>& adj,
             stack<int>& st,
             vector<bool>& visited,
             vector<bool>& inRecursion,
             int u) {

        visited[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]) {

            if(!visited[v]) {

                if(dfs(adj, st, visited, inRecursion, v)) {
                    return true;
                }
            }
            else if(inRecursion[v]) {
                return true;
            }
        }

        inRecursion[u] = false;

        st.push(u);

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<bool> visited(numCourses, false);

        vector<bool> inRecursion(numCourses, false);

        stack<int> st;

        vector<vector<int>> adj(numCourses);

        // build graph
        for(auto &edge : prerequisites) {

            int a = edge[0];
            int b = edge[1];

            adj[b].push_back(a);
        }

        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {

                if(dfs(adj, st, visited, inRecursion, i)) {
                    return {};
                }
            }
        }

        vector<int> topo;

        while(!st.empty()) {

            topo.push_back(st.top());

            st.pop();
        }

        return topo;
    }
};