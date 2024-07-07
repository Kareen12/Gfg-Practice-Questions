class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    int ans = 0;
    void solve(int src, int parent, int &timer, int c, int d, vector<int> &tin,
               vector<int> &low, vector<int> adj[], unordered_map<int, bool> &visited)
    {
        visited[src] = 1;
        low[src] = tin[src] = timer;
        timer++;

        for (auto nbr : adj[src])
        {
            if (nbr == parent)
                continue;

            if (!visited[nbr])
            {
                solve(nbr, src, timer, c, d, tin, low, adj, visited);
                // agar  nbr ka timer ow ho to
                low[src] = min(low[src], low[nbr]);
                if (low[nbr] > tin[src])
                {
                    if (nbr == c && src == d || nbr == d && src == c)
                    {
                        ans = 1;
                    }
                }
            }
            else
            {
                low[src] = min(low[nbr], low[src]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        unordered_map<int, bool> visited;
        int timer = 0;
        vector<int> tin(V, INT_MAX);
        vector<int> low(V, INT_MAX);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                solve(i, -1, timer, c, d, tin, low, adj, visited);
            }
        }
        return ans;
    }
};