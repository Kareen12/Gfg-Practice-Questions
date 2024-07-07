class Solution
{
public:
    void solve(int src, vector<int> adj[], vector<int> &visited, stack<int> &st)
    {
        visited[src] = 1;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                solve(nbr, adj, visited, st);
            }
        }
        st.push(src);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                solve(i, adj, visited, st);
            }
        }
        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

// Kanh's Algorithm - this can be  used to find cycle in directed graph using bfs(how? - if no topological exists then cycle is there otherwise not)
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        // vector<int> visited(V, 0);
        unordered_map<int, int> indegree;
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            res.push_back(frontNode);

            for (auto nbr : adj[frontNode])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        return res;
    }
};